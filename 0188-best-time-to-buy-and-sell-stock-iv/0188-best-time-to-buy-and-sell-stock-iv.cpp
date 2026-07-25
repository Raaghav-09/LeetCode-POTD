class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size() ; 

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,0))) ; 
        auto f = [&](auto&& f , bool buy , int idx , int t) -> int{
            if(t >= k) return 0 ; 
            if(idx == n) return 0 ;
            if(dp[idx][t][buy] != -1) return dp[idx][t][buy] ; 
            int ans = 0 ; 
            if(buy){
                int res = -prices[idx] + f(f,false,idx,t) ; 
                ans = max(res,f(f,buy,idx+1,t)) ; 
            }
            else{
                int res = prices[idx] + f(f,true,idx,t+1) ; ;
                ans = max(res,f(f,buy,idx+1,t)) ; 
            }
            return dp[idx][t][buy] = ans ; 
        };

        
        for(int idx=n-1 ; idx>=0 ; idx--){
            for(int t = 1 ; t<= k ; t++){
                for(int buy = 0 ; buy <= 1 ; buy++){
                    int ans = 0 ; 
                    if(buy){
                        int res = -prices[idx] + dp[idx][t][0] ; 
                        ans = max(res,dp[idx+1][t][buy]) ; 
                    }
                    else{
                        int res = prices[idx] + dp[idx][t-1][true] ; ;
                        ans = max(res,dp[idx+1][t][buy]) ; 
                    }  
                    dp[idx][t][buy] = ans ; 
                }
            }
        }

        return dp[0][k][1] ; 
    }
};