class Solution {
public:
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        vector<vector<int>> adj(n) ; 
        map<pair<int,int>,int> edgeInd ; 
        for(int i=0 ; i<n-1 ; i++){
            int u = edges[i][0] , v = edges[i][1] ; 
            adj[u].push_back(v) ; 
            adj[v].push_back(u) ; 
            edgeInd[make_pair(u,v)] = i ; 
            edgeInd[make_pair(v,u)] = i ; 
        }

        int root = 0 ; 
        vector<int> parent(n,0) ; 
        auto buildParent = [&](auto&& buildParent ,int node , int par) -> void{
            parent[node] = par ; 
            for(auto adjNode : adj[node]){
                if(adjNode != par){
                    buildParent(buildParent ,adjNode,node) ; 
                }
            }
        };

        buildParent(buildParent , 0 , -1) ; 
        vector<int> edgesTaken ; 
        // vector<int> nodesToChange ; 

        auto dfs = [&](int node , auto&& dfs) -> void{
            
            for(auto adjNode : adj[node]){
                if(adjNode != parent[node]){
                    dfs(adjNode , dfs) ; 
                }
            }

            if(start[node] != target[node] && node!=0){
                
                start[node] = (start[node] == '0' ? '1' : '0');
                start[parent[node]] = (start[parent[node]] == '0' ? '1' : '0') ;
                // edgesTaken.insert(edgeInd[make_pair(node,parent[node])]) ; 
                edgesTaken.push_back(edgeInd[make_pair(node,parent[node])]) ; 
            }
        };

        // also if we have to change odd no of vertices answer will be -1 always ...
        dfs(0,dfs) ; 
        if(start != target) return {-1} ; 
        sort(edgesTaken.begin(),edgesTaken.end()) ; 
        return edgesTaken ; 
    }
};