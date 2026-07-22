class Solution {
public:
    using ll = long long ; 
    void dijkastra(vector<vector<pair<int,int>>>& adj , int src , vector<ll>& dist){
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq ; 
        pq.push(make_pair(0,src)) ; 
        dist[src] = 0 ; 
        while(pq.size()){
            auto [dis,node] = pq.top() ; pq.pop() ; 

            if(dis > dist[node]) continue ; 
            for(auto& [adjNode,w] : adj[node]){
                if(dist[adjNode] > w + dis){
                    dist[adjNode] = w + dis ; 
                    pq.push(make_pair(dist[adjNode],adjNode)) ; 
                }
            }
        }
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        // 0 to n-1
        // we want what mst 
        /*
        src1 -------- dest.    999 -> Still you need to cover node
        src1 -------- dest.   1999 -> All nodes will be covered 

        src2 -------- dest.    999 -> Still you need to cover node
        src2 -------- dest.   1999 -> All nodes will be covered 

        weight >= 1
        */ 

        vector<vector<pair<int,int>>> adjT(n) , adj(n) ; 
        for(auto& edge : edges){
            int u = edge[0] , v = edge[1] , w = edge[2] ; 

            adj[u].push_back(make_pair(v,w)) ; 
            adjT[v].push_back(make_pair(u,w)) ; 
        }

        vector<ll> dist1(n,1e11) , dist2(n,1e11) , dist3(n,1e11) ; 

        dijkastra(adj,src1,dist1) ; 
        dijkastra(adj,src2,dist2) ; 
        dijkastra(adjT,dest,dist3) ; 

        ll ans = LLONG_MAX ; 
        for(int i=0 ; i<n ; i++){
            // if(dist1[i] == LLONG_MAX || dist2[i] == LLONG_MAX || dist3[i] == LLONG_MAX) continue ; 
            ll res = dist1[i] + dist2[i] + dist3[i] ; 
            ans = min(ans,res) ; 
        }
        if(ans >= 1e11) return -1 ; 
        return ans ; 
    }
};