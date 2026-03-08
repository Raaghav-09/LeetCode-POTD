class Solution {
public:
    using ll = long long ; 

    const int mod = 1e9 + 7 ; 

    ll binpow(ll a, ll b , int mod = (1e9 + 7)){
        ll res = 1 ; 
        while(b){
            if(b & 1){
                res *= a ; 
                res %= mod ; 
            }
            a*=a ; 
            a %= mod ; 
            b >>= 1 ; 
        }
        return res%mod ; 
    }

    void builtFact(ll n , vector<ll>& fact , vector<ll>& ifact , int mod = (1e9 + 7)){
        fact.assign(n+1 , 1) ; 
        ifact.assign(n+1 , 1) ; 
        for(ll i=1 ; i<=n ; i++){
            fact[i] = fact[i-1]* i ; 
            fact[i] %= mod ; 
        }

        ifact[n] = binpow(fact[n] , mod - 2 , mod) ; 

        for(ll i=n-1 ; i>=0 ; i--){
            ifact[i] = (i+1)*ifact[i+1] ; 
            ifact[i] %= mod ; 
        }
    }

    ll nCr(ll n , ll r , vector<ll>& fact , vector<ll>& ifact){
        ll ans = 1 ; 
        ans = fact[n] ; 
        ans = (ans * ifact[n-r]) % mod ; 
        ans = (ans * ifact[r]) % mod ; 

        return ans ; 
    }

    int countAnagrams(string s) {
        int n = s.size() ; 
        int ans = 1 ; 
        int i = 0 ; 

        vector<ll> fact , ifact ; 
        builtFact(1e5+5 , fact , ifact) ; 
        while(i<n){
            map<char,int> mp ; 
            int cnt = 0 ; 
            while(i<n && s[i] != ' '){
                mp[s[i]]++ ; 
                cnt++ ; 
                i++ ; 
            }
            i++ ; 

            ans = (ans * fact[cnt]) % mod ; 

            for(auto [ch , freq] : mp){
                ans = (ans * ifact[freq]) % mod ; 
            }
        }


        return ans ;
    }
};