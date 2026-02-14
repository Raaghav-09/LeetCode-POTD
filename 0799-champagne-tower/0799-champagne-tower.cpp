class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        /*       1        -> (0,0)
                1 1       -> (1,0) , (1,1)
               1 1 1      -> (2,0) , (2,1) , (2,2)
              1 1 1 1     -> (3,0) , (3,1) , (3,2) (3,3)
             1 1 1 1 1    -> So on ............
            1 1 1 1 1 1
        */
        vector<vector<double>> dp(query_row+1 , vector<double>(query_row+1 , 0LL)) ; 
        dp[0][0] = poured*1LL ; 
        for(int i=1 ; i<=query_row ; i++){
            for(int j=0 ; j<=i ; j++){
                if(j==0){
                    if(dp[i-1][j] > 1) dp[i][j] = (dp[i-1][j]-1)/2.0 ; 
                }
                else if(j==i){
                    if(dp[i-1][j-1] > 1) dp[i][j] = (dp[i-1][j-1]-1)/2.0 ; 
                }
                else{
                    if(dp[i-1][j-1] > 1) dp[i][j] = dp[i-1][j-1] - 1 ; 
                    if(dp[i-1][j] > 1) dp[i][j] += dp[i-1][j] - 1 ; 
                    // dp[i][j] = (dp[i-1][j-1]-1 + dp[i-1][j]-1)/2.0 ; 
                    dp[i][j] = dp[i][j]/2.0 ; 
                }
            }
        }
        return dp[query_row][query_glass] >= 1 ? 1.0 : dp[query_row][query_glass]  ; 
    }
};