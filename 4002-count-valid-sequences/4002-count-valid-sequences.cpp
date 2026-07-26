class Solution {
public:
    const int mxn = 5e5 + 5 ;
    using ll = long long ; 
    const ll mod = 1e9 + 7 ; 

    ll binExpo(ll base , ll power){
        ll res = 1 ; 
        while(power){
            if(power % 2){
                res *= base ; 
                res %= mod ; 
            }
            base *= base ; 
            base %= mod; 
            power /= 2 ; 
        }
        return res ; 
    }
    vector<ll> fact, invFact ; 
    ll count(int n , int k){
        // n-1Ck-1
        return ncr(n-1,k-1) ; 
    }
    ll ncr(int n , int k){
        if(n < k || k < 0 || n < 0) return 0 ;
        if(n == k) return 1 ; 
        ll ans = fact[n] * invFact[n-k] ; 
        ans %= mod ; 
        ans *= invFact[k] ; 
        ans %= mod ;
        return ans ;
    }
    int countValidSequences(int n, int k) {
        fact.assign(n+1,1) , invFact.assign(n+1,1) ; 
        for(int i=1 ; i<n+1 ; i++){
            fact[i] = fact[i-1] * i ; 
            fact[i] %= mod ; 
        }
        invFact[n+1-1] = binExpo(fact[n+1-1],mod-2) ; 

        for(int i=n+1-2 ; i>=0 ; i--){
            invFact[i] = ((i+1) * invFact[i+1] ) % mod ; 
        }
        ll ans = count(n,k) ;
        if((n-k) % 2 == 0){
            int m = (n-k)/2 ; 
            ans -= ncr(m + k - 1, k - 1) ;
        }
        ans += mod ; 
        ans %= mod ; 

        return ans ; 
    }
};