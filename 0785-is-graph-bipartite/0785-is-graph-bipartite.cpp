class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj){
        int n = adj.size() ;
        vector<int> color(n,-1) ; 
        vector<int> visited(n,0) ; 
        auto dfs = [&](auto&& dfs , int col , int node) -> bool{
            visited[node] = 1 ; 
            color[node] = col ; 

            for(auto adjNode : adj[node]){
                if(color[adjNode] == col) return false ; 
                if(!visited[adjNode]){
                    if(!dfs(dfs,1-col,adjNode)) return false ; 
                }
            }

            return true ; 
        };

        for(int i=0 ; i<n ; i++){
            if(!visited[i]){
                bool flag = dfs(dfs,0,i) ; 
                if(!flag) return false ;
            }
        }

        return true ; 
    }
};