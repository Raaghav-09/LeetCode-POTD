class Solution {
public:
    typedef long long ll ;
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size() ; 
        if(n==1 || k==0) return 0 ;

        vector<ll> profit(k+1,0) ; 
        vector<ll> longProf(k+1,INT_MIN) ; 
        vector<ll> shortProf(k+1,INT_MIN) ; 

        for(int p : prices){
            for(int t = k ; t>=1 ; t--){
                profit[t] = max({profit[t],longProf[t]+p,shortProf[t]-p}) ; 

                longProf[t] = max(longProf[t],profit[t-1]-p) ; 
                shortProf[t] = max(shortProf[t],profit[t-1]+p);
            }
            
        }

        return profit[k] ; 
    }
};