class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ; 

        /*
        need to know what will be the max profit between day i to day j
 
        */

        vector<vector<int>> pre(n+1,vector<int>(n+1,0)) ; 
        for(int i=0 ; i<n ; i++){
            int buy = prices[i] ; 
            pre[i][i] = 0 ; 
            for(int j=i+1 ; j<n ; j++){
                buy = min(buy,prices[j]) ; 
                pre[i][j] = max(prices[j]-buy , pre[i][j-1] ) ; 
            }
        }

        // now i know what will be maximum profit between day i and j 
        /*

        dp[i][k] = maximum profit earned if I made exactly k transaction till index i
        dp[i][k] = max(dp[i-1][k-1] + pre[i-1][i],dp[i-2][k-1] + pre[i-2][i] + .......... dp[0][k-1] + pre[i-]
        
        */

        vector<vector<int>> dp(n+1,vector<int>(k+1,0)) ; 
        // vector<int> preMx(n,0) ; 
        for(int i=1 ; i<n ; i++){
            for(int t=1 ; t<=k ; t++){
                int val = 0 ; 
                for(int j=i ; j>=0 ; j--){
                    val = max(val, dp[j][t-1] + pre[j][i]);
                }
                dp[i][t] = val ; 
            }
        }
        return dp[n-1][k] ; 
    }
};