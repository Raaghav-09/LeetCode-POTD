class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1)) ; 
        auto f = [&](int l , int r , auto&& f) -> int{
            if(l >= r) return 0 ; 
            if(dp[l][r] != -1) return dp[l][r] ; 
            int ans = INT_MAX  ; 
            for(int i = l ; i < r ; i++){
                int res = i + max( f(l,i-1,f) , f(i+1,r,f) ) ; 
                ans = min(ans , res) ; 
            }

            return dp[l][r] = ans ; 
        };

        return f(1,n,f) ; 
    }
};