class Solution {
public:
/*
// Memoization giving TLE because of Auxilary Time complexity 
    int f(string s , string t , int idx1 , int idx2,vector<vector<int>>& dp){
        int n1 = s.size() , n2 = t.size() ; 
        if(idx1==-1 && idx2==-1) return 1 ; 
        if(idx2<0) return 1 ; 
        if(idx1<0) return 0 ; 
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2] ; 
        if(s[idx1]==t[idx2]){
            int take = f(s,t,idx1-1,idx2-1,dp) ; 
            int notTake = f(s,t,idx1-1,idx2,dp) ; 
            return dp[idx1][idx2] = take+notTake ; 
        }
        else{
            return dp[idx1][idx2] = f(s,t,idx1-1,idx2,dp) ; 
        }
    }
*/
    int numDistinct(string s, string t) {
        int n1 = s.size() , n2 = t.size() ; 
        vector<vector<double>> dp(n1+1,vector<double>(n2+1,1)) ; 
        for(int i=0 ; i<=n1 ; i++){
            dp[i][0] = 1 ; 
        }
        for(int j=1 ; j<=n2 ; j++){
            dp[0][j] = 0 ; 
        }
        for(int i=1 ; i<=n1 ; i++){
            for(int j=1 ; j<=n2 ; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1] ; 
                }
                else{
                    dp[i][j] = dp[i-1][j] ; 
                }
            }
        }
        return dp[n1][n2] ; 
    }
};