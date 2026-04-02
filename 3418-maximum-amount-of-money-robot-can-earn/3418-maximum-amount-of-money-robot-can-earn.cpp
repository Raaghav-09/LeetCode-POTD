class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size() , m = coins[0].size();
        /*
        0  1 -1 
        1 -2  3 
        2 -3  4
        Think of robot have ability to neutralize K ces and now solve this problem 

        DP -> Repeating Subproblem 

        State :- dp(i,j,k) -> maximum coins in i,j ce with using at max k times the power
        Transition :- 
        if coins[i][j] >= 0 
            dp[i][j][k] = max(dp[i-1][j][k] , dp[i][j-1][k]) + coins[i][j] 
        else 
            two options:- bear the loss or use power
            if k>0
                dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]) + coins[i][j] , max(dp[i-1][j][k-1],dp[i][j-1][k-1])) ;
            else k == 0
                dp[i][j][k] = max(dp[i-1][j][k],dp[i][j-1][k]) - coins[i][j]  ;

        TC :- O(n*m*K) SC :- O(n*m*K) can Optimized to O(m*K)
        */

        int K = 2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(K+1, INT_MIN)));

        for(int k = 0; k <= K; k++){
            dp[0][0][k] = coins[0][0];
            if(coins[0][0] < 0 && k > 0){
                dp[0][0][k] = max(dp[0][0][k], 0);
            }
        }

        for(int j = 1; j < m; j++){
            for(int k = 0; k <= K; k++){
                if(dp[0][j - 1][k] != INT_MIN){
                    dp[0][j][k] = max(dp[0][j][k], dp[0][j - 1][k] + coins[0][j]);
                }
                if(coins[0][j] < 0 && k > 0 && dp[0][j - 1][k - 1] != INT_MIN){
                    dp[0][j][k] = max(dp[0][j][k], dp[0][j - 1][k - 1]);
                }
            }
        }

        for(int i = 1; i < n; i++){
            for(int k = 0; k <= K; k++){
                if(dp[i - 1][0][k] != INT_MIN){
                    dp[i][0][k] = max(dp[i][0][k], dp[i - 1][0][k] + coins[i][0]);
                }
                if(coins[i][0] < 0 && k > 0 && dp[i - 1][0][k - 1] != INT_MIN){
                    dp[i][0][k] = max(dp[i][0][k], dp[i - 1][0][k - 1]);
                }
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                for(int k = 0; k <= K; k++){
                    int best = INT_MIN;

                    if(dp[i - 1][j][k] != INT_MIN){
                        best = max(best, dp[i - 1][j][k] + coins[i][j]);
                    }
                    if(dp[i][j - 1][k] != INT_MIN){
                        best = max(best, dp[i][j - 1][k] + coins[i][j]);
                    }

                    if(coins[i][j] < 0 && k > 0){
                        if(dp[i - 1][j][k - 1] != INT_MIN){
                            best = max(best, dp[i - 1][j][k - 1]);
                        }
                        if(dp[i][j - 1][k - 1] != INT_MIN){
                            best = max(best, dp[i][j - 1][k - 1]);
                        }
                    }

                    dp[i][j][k] = best;
                }
            }
        }

        return dp[n - 1][m - 1][K];
    }
};