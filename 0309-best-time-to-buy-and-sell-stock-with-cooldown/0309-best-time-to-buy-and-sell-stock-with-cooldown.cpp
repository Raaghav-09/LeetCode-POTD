class Solution {
public:
    int dp[5005][2] ; 
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ; 
        memset(dp,-1,sizeof(dp)) ; 

        auto f = [&](auto&& f , int idx , bool canBuy) -> int{
            if(idx >=n){
                return 0 ; 
            }   
            if(dp[idx][canBuy] != -1) return dp[idx][canBuy] ; 
            int profit = 0 ; 
            if(canBuy){
                profit = max(-prices[idx] + f(f,idx+1,false) , f(f,idx+1,true)) ; 
            }
            else{
                profit = max(prices[idx] + f(f,idx+2,true) , f(f,idx+1,false)) ; 
            }
            return dp[idx][canBuy] = profit ; 
        };

        return f(f,0,true) ; 
    }
};