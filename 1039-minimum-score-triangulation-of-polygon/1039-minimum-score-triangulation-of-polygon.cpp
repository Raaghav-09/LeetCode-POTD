class Solution {
public:
    int f(int i , int j , vector<int>& values,vector<vector<int>> &dp){
        if(abs(j-i)<=1) return 0 ; 
        if(dp[i][j]!=-1) return dp[i][j] ; 
        int mn = INT_MAX ; 
        for(int k = i+1 ; k<j ; k++){
            int cnt = values[i]*values[j]*values[k] + f(i,k,values,dp) + f(k,j,values,dp) ; 
            mn = min(mn,cnt) ; 
        }
        return dp[i][j] = mn ; 
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size() ; 
        vector<vector<int>> dp(n,vector<int>(n,0)) ; 
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=i+2 ; j<n ; j++){
                int mn = INT_MAX ; 
                for(int k=i+1 ; k<j ; k++ ){
                    int cnt = values[i]*values[j]*values[k] + dp[i][k] + dp[k][j] ; 
                    mn = min(mn,cnt) ; 
                }
                dp[i][j] = mn ; 
            }
        }
        return dp[0][n-1] ; 
    }
};