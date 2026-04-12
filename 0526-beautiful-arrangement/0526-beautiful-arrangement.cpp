class Solution {
public:
    int countArrangement(int n) {
        vector<vector<int>> dp(n+1,vector<int>(1<<(n+1) , -1)) ; 
        auto f = [&](int ind , int mask , auto&& f) -> int{
            if(ind == n){
                return 1 ; 
            }
            if(dp[ind][mask] != -1) return dp[ind][mask] ; 
            int ways = 0 ; 
            int pos = ind+1 ; 
            for(int j=1 ; j<=n ; j++){
                if((j%pos == 0 || pos%j == 0) && (mask & 1<<j) == 0 ){
                    ways += f(ind+1,mask | 1<<j , f) ; 
                }
            }

            return dp[ind][mask] = ways ; 
        };

        return f(0,0,f) ; 
    }
};