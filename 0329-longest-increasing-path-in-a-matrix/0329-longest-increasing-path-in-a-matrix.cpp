class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() ; 

        vector<pair<int,int>> dirs = {{-1,0},{0,-1},{0,1},{1,0}} ; 

        vector<vector<bool>> visited(n,vector<bool>(m,false)) ; 
        vector<vector<int>> dp(n , vector<int>(m , -1)) ; 

        auto dfs = [&](auto&& dfs , int r , int c) -> int{
            int mx = 1 ; 
            if(dp[r][c] != -1) return dp[r][c] ; 
            for(auto& [dx,dy] : dirs){
                int nx = dx + r , ny = dy + c ; 
                if(nx >= 0 && nx<n && ny >=0 && ny < m && !visited[nx][ny] && matrix[nx][ny] > matrix[r][c]){
                    visited[nx][ny] = true ; 
                    int pathLength = 1 + dfs(dfs , nx , ny) ; 
                    mx = max(pathLength , mx) ; 
                    visited[nx][ny] = false ; 
                }
            }

            return dp[r][c] = mx ; 
        } ; 

        int ans = 1 ; 
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                int path = dfs(dfs,i,j) ; 
                ans = max(ans , path) ; 
            }
        }

        return ans ; 
    }
};