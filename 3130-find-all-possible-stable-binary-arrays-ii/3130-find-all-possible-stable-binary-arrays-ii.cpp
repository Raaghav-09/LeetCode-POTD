class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int mod = 1e9 + 7;
        
        // dp[i][j][0] = valid arrays using 'i' zeros, 'j' ones, ending in 0
        // dp[i][j][1] = valid arrays using 'i' zeros, 'j' ones, ending in 1
        vector<vector<vector<long long>>> dp(zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2, 0)));

        // Base cases: If we only have 0s or only 1s, there is 1 valid way as long as we don't exceed the limit
        for (int i = 1; i <= min(zero, limit); i++) dp[i][0][0] = 1;
        for (int j = 1; j <= min(one, limit); j++) dp[0][j][1] = 1;

        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                
                // Calculate arrays ending in 0
                // We can append a 0 to any valid array ending in 0 OR ending in 1
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % mod;
                
                // If appending this 0 created a streak strictly greater than limit, we subtract the illegal state
                if (i > limit) {
                    dp[i][j][0] = (dp[i][j][0] - dp[i - limit - 1][j][1] + mod) % mod;
                }

                // Calculate arrays ending in 1
                // We can append a 1 to any valid array ending in 0 OR ending in 1
                dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % mod;
                
                // If appending this 1 created a streak strictly greater than limit, we subtract the illegal state
                if (j > limit) {
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j - limit - 1][0] + mod) % mod;
                }
            }
        }

        // The answer is the sum of valid arrays ending in 0 and ending in 1
        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }
};