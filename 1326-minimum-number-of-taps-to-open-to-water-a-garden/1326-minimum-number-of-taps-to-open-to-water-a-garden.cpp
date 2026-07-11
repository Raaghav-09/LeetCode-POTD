class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector<int> dp(n+1, 1e9); 
        dp[0] = 0; 

        for(int i=0 ; i<=n ; i++){
            int l = max(0, i - ranges[i]); 
            int r = min(n, i + ranges[i]); 

            int mn = 1e9; 
            
            for(int j=l ; j<=r ; j++){ 
                mn = min(dp[j], mn); 
            }
            for(int j=l ; j<=r ; j++){
                dp[j] = min(dp[j], 1 + mn); 
            }
        }
        
        if(dp[n] == 1e9) return -1; 
        return dp[n]; 
    }
};