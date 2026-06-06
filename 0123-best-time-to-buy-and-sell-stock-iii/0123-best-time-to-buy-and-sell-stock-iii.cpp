class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ; 
        
        vector<int> preProfit(n) ; 
        int buy = prices[0] ; 
        preProfit[0] = 0 ; 
        for(int i=1 ; i<n ; i++){
            buy = min(buy,prices[i]) ; 
            preProfit[i] = max(preProfit[i-1], prices[i] - buy);
        }

        vector<int> suffProfit(n) ; 
        suffProfit[n-1] = 0 ; 
        int sell = prices[n-1] ; 
        for(int i=n-2 ; i>=0 ; i--){
            sell = max(sell,prices[i]) ; 
            suffProfit[i] = max(suffProfit[i+1],sell-prices[i]) ; 
        }

        int ans = 0 ; 

        for(int i=0 ; i<n ; i++){
            ans = max(ans,preProfit[i] + suffProfit[i]) ; 
        }
        return ans ; 
    }
};