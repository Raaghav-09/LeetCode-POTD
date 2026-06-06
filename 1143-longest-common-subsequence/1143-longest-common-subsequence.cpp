class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size() , m = t2.size() ; 

        /*
        dp[i][j] = lcs of t1[0 to i] and t2[0 to j]

        if(t1[i] == t2[j]) dp[i][j] = 1 + dp[i-1][j-1] 
        dp[i][j] = max(dp[i-1][j] , dp[i][j-1] , dp[i][j]) ; 
        */
        vector<vector<int>> dp(n,vector<int>(m,0)) ; 
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(t1[i] == t2[j]){
                    if(i == 0 || j == 0) dp[i][j] = 1 ; 
                    else dp[i][j] = 1 + dp[i-1][j-1] ; 
                }
                if(i == 0 && j == 0) dp[i][j] = max(0,dp[i][j]) ; 
                else if(i == 0) dp[i][j] = max(dp[i][j],dp[i][j-1]) ; 
                else if(j == 0) dp[i][j] = max(dp[i][j],dp[i-1][j]) ; 
                else dp[i][j] = max({dp[i][j] , dp[i-1][j] , dp[i][j-1]}) ; 
            }
        }

        return dp[n-1][m-1] ; 
    }
};