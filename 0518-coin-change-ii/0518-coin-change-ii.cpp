class Solution {
public:
    using ll = long long ; 
    unsigned int dp[5005] ; 
    const int mod = 1e9 + 7 ; 
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ; 
        /*
        dp[i][j] = no of ways to make amount j using coins from 0 to i 
        dp[i][j] = dp[i-1][j] + dp[i-1][j-coins[0]] + dp[i-1][j-2*coins[0]] + .....
        */
        memset(dp,0,sizeof(dp)) ; 
        dp[0] = 1 ; 
        for(int i=0 ; i<n ; i++){
            for(int s = coins[i]; s <= amount; s++) {
                dp[s] += dp[s - coins[i]];
            }
        }

        return dp[amount] ; 
    }
};