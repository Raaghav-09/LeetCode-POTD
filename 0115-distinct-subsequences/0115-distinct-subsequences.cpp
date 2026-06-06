class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size() , m = t.size() ; 

        /*
        dp[i][j] = no of distinct subsequences such that subseq(s) = substr(0 .. j) in t

        if(s[i] == t[j]) dp[i][j] = dp[i][j-1] + dp[i-1][j] ;
        else dp[i][j] = dp[i-1][j]
        */

        vector<vector<unsigned int>> dp(n+1,vector<unsigned int>(m+1,0)) ;
        for(int i=0 ; i<=n ; i++){
            dp[i][0] = 1 ; 
        }
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1] ; 
                }
                else dp[i][j] = dp[i-1][j] ; 
            }
        }

        return dp[n][m] ; 
    }
};