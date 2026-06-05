class Solution {
public:
    int dp[75][75][75] ; 
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 
        /*
        dp[i][j][0] = 
        */
        memset(dp,-1,sizeof(dp)) ; 
        auto f = [&](auto&& f , int i , int j1 , int j2) -> int{
            if(i == n) return 0 ;
            if(dp[i][j1][j2] != -1) return dp[i][j1][j2] ; 
            int base = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2] ; 
            int points = 0 ; 
            for(int k1 = max(0,j1-1) ; k1<=min(m-1,j1+1) ; k1++){
                for(int k2 = max(0,j2-1) ; k2<=min(m-1,j2+1) ; k2++){
                    points = max(points , base + f(f,i+1,k1,k2)) ; 
                }
            }

            return dp[i][j1][j2] = points ; 
        };

        return f(f,0,0,m-1) ; 
    }
};