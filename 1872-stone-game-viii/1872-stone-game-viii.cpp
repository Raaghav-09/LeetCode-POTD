class Solution {
public:
    using ll = long long ; 
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size() ; 

        vector<ll> prefix(n,0) ; 
        prefix[0] = stones[0] ; 
        for(ll i=1 ; i<n ; i++) prefix[i] = prefix[i-1] + stones[i] ; 

        /*
        -10 -12 -10 -12
        -10 -22 -32 -44
        */
        vector<ll> dp(n,-1e17) ; 
        auto f = [&](auto&& f , ll ind) -> ll{
            if(ind == n-2) return prefix[ind+1] ; 
            if(dp[ind] !=2 -1e17) return dp[ind] ; 
            
            ll ans = max(prefix[ind+1]-f(f,ind+1),f(f,ind+1)) ; 

            return dp[ind] = ans ; 
        };

        return f(f,0) ; 
    }
};