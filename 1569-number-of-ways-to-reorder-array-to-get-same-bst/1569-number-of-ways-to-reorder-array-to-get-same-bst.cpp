class Solution {
public:
    using ll = long long ; 
    const ll mod = 1e9 + 7 ;

    ll expo(ll base , ll power){
        ll res = 1 ; 
        while(power){
            if(power&1){
                res *= base ; 
                res %= mod ; 
            }
            power /= 2 ; 
            base *= base ; 
            base %= mod ; 
        }
        return res ; 
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size() ; 
        vector<ll> fact(n+1,1) , invFact(n+1,1); 
        for(int i=1 ; i<=n ; i++){
            fact[i] = fact[i-1] * i ; 
            fact[i] %= mod ; 
        }
        invFact[n] = expo(fact[n],mod-2) ; 
        for(int i=n-1 ; i>=0 ; i--){
            invFact[i] = invFact[i+1] * (i+1) ; 
            invFact[i] %= mod ; 
        }

        auto nCr = [&](ll n, ll r)-> ll{
            ll ans = fact[n] * invFact[r] ; 
            ans %= mod ; 
            ans *= invFact[n-r] ; 
            ans %= mod ; 
            return ans ; 
        };

        auto func = [&](auto&& func , int i , int mx , int mn) -> ll{
            // if(mx == mn) return 1 ; 
            int f = nums[i] ; 
            int l = 0 , r = 0 ;  
            int lmn = mn , lmx = f ;
            int rmn = f , rmx = mx ; 
            int lidx = -1 , ridx = -1 ; 
            for(int it = i+1 ; it <= n-1 ; it++){
                if(nums[it] < mx && nums[it] > mn){
                    if(nums[it] > f){
                        if(r == 0) ridx = it ; 
                        r++ ; 
                    }
                    else{
                        if(l == 0) lidx = it ; 
                        l++ ; 
                    }
                }
            }

            ll ans = nCr(l+r,r) ;
            if(lidx != -1) ans = (ans*func(func,lidx,lmx,lmn)) % mod ;
            if(ridx != -1) ans = (ans*func(func,ridx,rmx,rmn)) % mod ;
            return ans ;  
        };

        int ans = (func(func,0,INT_MAX,INT_MIN) - 1 + mod) % mod ; 

        return ans ; 
    }
};