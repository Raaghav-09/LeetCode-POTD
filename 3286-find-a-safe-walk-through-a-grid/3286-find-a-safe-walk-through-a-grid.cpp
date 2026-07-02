class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size() , m = grid[0].size() ;

        // vector<vector<int>> dp(n,vector<int>(m,0)) ; 
        // for(int i=0 ; i<n ; i++){
        //     for(int j=0 ; j<m ; j++){
        //         if(i == 0 && j == 0) dp[i][j] = health - grid[i][j] ; 
        //         else if(i == 0) dp[i][j] = dp[i][j-1] - grid[i][j] ; 
        //         else if(j == 0) dp[i][j] = dp[i-1][j] - grid[i][j] ; 
        //         else{
        //             dp[i][j] = max(dp[i][j-1],dp[i-1][j]) - grid[i][j] ; 
        //         }
        //     }
        // }

        // return dp[n-1][m-1] > 0 ; 
        // grid[n-1][m-1] = 0 ; 
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}} ; 
        vector<vector<int>> dis(n,vector<int>(m,1e9)) ; 
        dis[0][0] = grid[0][0] ; 
        deque<pair<int,int>> dq ; 
        dq.push_back({0,0}) ; 

        while(!dq.empty()){
            auto [r, c] = dq.front();
            dq.pop_front();
            
            if(r == n-1 && c == m-1){
                return health - dis[r][c] > 0 ;
            }
            
            for(int i = 0; i < 4; i++){
                int nr = r + dirs[i].first ;
                int nc = c + dirs[i].second ;
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int cost = grid[nr][nc];
                    
                    if(dis[r][c] + cost < dis[nr][nc]) {
                        dis[nr][nc] = dis[r][c] + cost;
                        
                        if(cost == 1){
                            dq.push_back({nr, nc});
                        } 
                        else{
                            dq.push_front({nr, nc});
                        }
                    }
                }
            }
        } 

        return false ; 

    }
};