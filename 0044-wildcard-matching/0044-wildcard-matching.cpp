class Solution {
public:
    bool isMatch(string s, string t) {
        int n = s.size() , m = t.size() ; 

        vector<vector<int>> dp(n+1,vector<int>(m+1,false)) ; 
        dp[0][0] = true ; 
        /*
        dp[i][j] = is the s from 0 to i can be match with t from 0 to j

        if(t[j] == '*') dp[i][j] = dp[i][j-1] || dp[i-1][j]
        if(t[j] == s[i] || t[j] == '?') dp[i][j] = dp[i-1][j-1] 
        */

        for(int j = 1; j <= m; j++){
            if(t[j-1] == '*'){
                dp[0][j] = dp[0][j - 1]; 
            }
        }

        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(t[j-1] == '*') dp[i][j] = dp[i][j-1] || dp[i-1][j] ;
                else if(t[j-1] == s[i-1] || t[j-1] == '?') dp[i][j] = dp[i-1][j-1] ; 
                else dp[i][j] = false; 
            }
        }

        return dp[n][m] ; 

    }
};