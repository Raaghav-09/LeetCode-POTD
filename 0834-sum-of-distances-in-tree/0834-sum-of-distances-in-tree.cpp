class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n) ; 
        for(auto edge : edges){
            int u = edge[0] , v = edge[1] ; 
            adj[u].push_back(v) ; 
            adj[v].push_back(u) ; 
        }
        
        int root = 0 ; 
        vector<int> dp(n,0) ; 
        vector<int> subtree(n,1) ; 
        vector<int> ans(n,0) ;
        
        auto dfs = [&](auto&& dfs , int node , int parent)->void{
            for(auto adjNode : adj[node]){
                if(adjNode == parent) continue ; 
                dfs(dfs,adjNode,node) ; 
                dp[node] += dp[adjNode] + subtree[adjNode] ; 
                subtree[node] += subtree[adjNode] ; 
            }
            ans[node] = dp[node] ; 
        };

        dfs(dfs,root,-1) ; 

        auto dfs2 = [&](auto&& dfs2 , int node , int parent , int curr) -> void{
            for(auto adjNode : adj[node]){
                if(adjNode == parent) continue ; 
                int newVal = curr - subtree[adjNode] + (n - subtree[adjNode]) ; 
                ans[adjNode] = newVal ; 
                dfs2(dfs2,adjNode,node,newVal) ; 
            }
        };

        dfs2(dfs2,0,-1,ans[root]) ; 

        return ans ; 
    }
};