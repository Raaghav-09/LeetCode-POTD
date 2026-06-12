class Solution {
public:
    using ll = long long ;
    const ll mod = 1e9 + 7 ; 

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() , q = queries.size() ; 
        n++ ; 
        /*
        suppose distance between u and v = odd
        Then , 
        odd => no of one should be odd 
        even => no 

        It means in u to v we should have odd no of ones . 

        It just means we need to find distance between u to v => d 
        and ans = dC1 + dC3 + dC5 + ... dCd = 2^(d-1)
        ans *= pow(2,(n-1-d))
        */

        vector<ll> powerOf2(n,0) ; 
        powerOf2[0] = 1 ; 
        for(int i=1 ; i<n ; i++){
            powerOf2[i] = (powerOf2[i-1]*2) % mod ; 
        }

        vector<vector<int>> adj(n) ; 
        for(int i=0 ; i<n-1 ; i++){
            adj[edges[i][0]-1].push_back(edges[i][1]-1) ; 
            adj[edges[i][1]-1].push_back(edges[i][0]-1) ; 
        }


        // binary lifting table 
        int sz = log2(n) + 2 ; 
        vector<int> depth(n,0); 
        depth[0] = 0 ; 
        vector<vector<int>> par(n,vector<int>(sz,-1)) ; 
        auto dfs = [&](auto&& dfs , int node , int parent) -> void{
            if(parent != -1) depth[node] = depth[parent] + 1 ; 
            par[node][0] = parent ; 
            for(int i=1 ; i<sz ; i++){
                if(par[node][i-1] != -1) par[node][i] = par[par[node][i-1]][i-1] ; 
                else par[node][i] = -1 ; 
            }
            for(auto adjNode : adj[node]){
                if(adjNode == parent) continue ; 
                dfs(dfs,adjNode,node) ; 
            }
        };

        dfs(dfs,0,-1) ; 

        auto kthParent = [&](int k , int u) -> int{
            int node = u ; 
            for(int i=0 ; i<sz ; i++){
                if(((k) & (1 << i))){
                    node = par[node][i] ; 
                }
            }
            return node ; 
        };

        auto dist = [&](int u , int v)->int{
            if(depth[u] > depth[v]) swap(u,v) ; 
            // depth[u] <= depth[v]
            int d1 = depth[u] , d2 = depth[v] ; 
            int distance = 0 ; 
            if(d1 != d2){
                distance = d2 - d1 ; 
            }
            v = kthParent(distance,v) ; 

            if(u == v) return distance ; 
            int du = u , dv = v ; 
            for(int i=sz-1 ; i>=0 ; i--){
                if(par[du][i] != par[dv][i]){
                    du = par[du][i] , dv = par[dv][i] ; 
                }
            }

            int lca = par[du][0] ; 

            distance += 2*(depth[u] - depth[lca]) ; 

            return distance ; 
        };


        vector<int> ans ; 
        for(int i=0 ; i<q ; i++){
            int u = queries[i][0]-1 , v = queries[i][1]-1 ; 

            int distance = dist(u,v) ; 

            if(distance == 0){
                ans.push_back(0);
                continue;
            }

            ll res = 1 ; 
            res *= powerOf2[distance-1] ; 
            res %= mod ; 

            ans.push_back(res) ; 
        }

        return ans ;
    }
};