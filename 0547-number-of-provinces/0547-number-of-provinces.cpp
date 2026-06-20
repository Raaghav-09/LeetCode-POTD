class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ; 

        vector<int> vis(n,0) ;
        int cnt = 0 ; 

        auto dfs = [&](auto&& dfs , int node) -> void{
            vis[node] = 1 ; 
            for(int i=0 ; i<n ; i++){
                if(!vis[i] && isConnected[node][i]){
                    dfs(dfs,i) ; 
                }
            }
        };

        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                dfs(dfs,i) ; 
                cnt++ ; 
            }
        }
        return cnt ; 
    }
};