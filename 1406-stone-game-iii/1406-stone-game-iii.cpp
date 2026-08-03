class Solution {
public:
    using ll = long long ; 
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size() ;  

        vector<ll> dp(n,-1) ; 
        auto f = [&](auto&& f , int idx) -> ll{
            if(idx == n) return 0 ;
            if(dp[idx] != -1) return dp[idx] ; 
            ll ans = INT_MIN ; 
            ll sum = 0 ; 
            for(int i=idx ; i<min(idx+3,n) ; i++){
                sum += stoneValue[i] ; 
                ans = max(ans,sum - f(f,i+1)) ; 
            }

            return dp[idx] = ans ;
        };

        ll val = f(f,0) ; 

        if(val > 0) return "Alice" ; 
        else if(val < 0) return "Bob" ; 
        else return "Tie" ; 
    }
};