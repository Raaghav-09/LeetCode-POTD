class Solution {
public:
    using ll = long long ; 
    const ll mod = 1e9 + 7 ; 
    int numMusicPlaylists(int n, int goal, int k) {
        /*
        s1 s2 s3 s4 s5 s6 s7 s8 s9 s10

        dp[i][j] = no of ways in which i songs can be played to reach to the no of songs = j
                 = dp[]
        dp[i][j] = dp[i-1][j] + dp[i-1][j-1] 

        dp[i][j] = no of ways to reach goal = i such that at most j different songs are played
        dp[i][j] = dp[i-1][j]*(n-j+1) + dp[i-1][j-1]*(j-k)
        */

        vector<vector<ll>> dp(goal+1,vector<ll>(n+1,0)) ; 
        dp[0][0] = 1 ; 
        for(int i=1 ; i<=goal ; i++){
            for(int j=1 ; j<=min(n,i) ; j++){
                
                dp[i][j] = dp[i-1][j-1]*(ll)(n-j+1) ; 
                if(j > k){
                    dp[i][j] += dp[i-1][j]*(ll)(j-k) ; 
                }
                dp[i][j] %= mod ;

            }
        }

        return dp[goal][n] ; 
    }
};