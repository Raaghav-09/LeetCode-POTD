class Solution {
public:
    using ll = long long ; 
    const ll mod = 1e9 + 7 ; 
    int kInversePairs(int n, int k) {
        /*
        1 2 3 4 5 6 

        6 5 4 3 2 1 

        dp[i][j] = no of ways to have (1 to i) permutation in such a way that we have exactly j inversion
        dp[i][j] = dp[i-1][j] + dp[i-1][j-2] + dp[i-1][j-3] + ...  + dp[i-1][j-i+1]
        dp[i][j-1] = dp[i-1][j-1] + dp[i-1][j-2] + ............... + dp[i-1][j-i]

        dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-i]


        5 x x x x
        x 5 x x x 
        x x 5 x x
        x x x 5 x 
        x x x x 5
        */

        vector<vector<ll>> dp(n+1,vector<ll>(k+1,0)) ; 
        for(int i=0 ; i<=n ; i++) dp[i][0] = 1 ;  
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=k ; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1] ; 
                if(j>=i) dp[i][j] = (dp[i][j]-dp[i-1][j-i] + mod) % mod ;
                dp[i][j] %= mod; 
            }
        }

        return dp[n][k] ; 
    }
};