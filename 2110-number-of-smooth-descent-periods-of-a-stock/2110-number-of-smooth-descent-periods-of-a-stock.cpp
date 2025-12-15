class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size() ; 
        long long len = 1 ; 
        long long ans = 0 ; 
        int prev = prices[0] ; 
        for(int i=1 ; i<n ; i++){
            if(prices[i]==prev-1){
                prev = prices[i] ; 
                len++ ; 
            }
            else{
                ans += (len)*(len+1)/2LL ; 
                prev = prices[i] ; 
                len = 1 ;
            }
        }
        ans += (len)*(len+1)/2LL ; 
        return ans ; 
    }
};