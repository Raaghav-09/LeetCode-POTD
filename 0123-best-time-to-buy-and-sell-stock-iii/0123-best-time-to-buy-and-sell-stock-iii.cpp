class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ; 

        vector<int> pre(n,0) ; 
        int mn = prices[0] ; 
        for(int i=1 ; i<n ; i++){
            mn = min(mn,prices[i]) ; 
            pre[i] = prices[i] - mn ; 
            pre[i] = max(pre[i-1],pre[i]) ; 
        }

        vector<int> suff(n,0) ; 
        int mx = prices[n-1] ; 
        for(int i=n-2 ; i>=0 ; i--){
            mx = max(mx,prices[i]) ; 
            suff[i] = mx - prices[i] ;
            suff[i] = max(suff[i],suff[i+1]) ; 
        }

        int ans = max(pre[n-1],suff[0]) ; 

        for(int i=0 ; i<n-1 ; i++){
            ans = max(ans,pre[i]+suff[i]) ; 
        }

        return ans ; 
    }
};