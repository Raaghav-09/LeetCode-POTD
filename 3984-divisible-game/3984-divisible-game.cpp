class Solution {
public:
    using ll = long long ; 
    const int mod = 1e9 + 7 ; 
    static const int N = 1e6 + 5 ; 
    int spf[N] ;    
    void buildSpf(){
        for(int i=2 ; i*i<=N ; i++){
            if(spf[i] != i) continue ; 
            for(int j=i ; j<N ; j+=i){
                if(spf[j] == j) spf[j] = i ; 
            }
        }
    }
    int divisibleGame(vector<int>& nums) {
        for(int i=0 ; i<N ; i++){
            spf[i] = i ; 
        }
        buildSpf() ; 
        int n = nums.size() ; 
        set<int> primes ; 
        primes.insert(2) ;
        for(int i=0 ; i<n ; i++){
            int temp = nums[i] ; 
            while(temp > 1){
                int p = spf[temp] ; 
                primes.insert(p) ; 
                temp /= spf[temp] ; 
            }
        }

        ll max_mx = -1e18 ; 
        ll best_k = -1 ;
        for(auto prime : primes) cout << prime << " " ; 
        for(auto& prime : primes){
            ll curr = 0 , mx = -1e18 ; 
            for(int i=0 ; i<n ; i++){
                int val = nums[i] ; 
                if(val % prime != 0) val *= -1 ; 

                if(curr < 0) curr = val ; 
                else curr += val ; 

                mx = max(mx,curr) ; 
            }

            if(mx > max_mx){
                max_mx = mx ;
                best_k = prime ;
            }
        }

        ll ans = (max_mx * best_k) % mod ; 
        if(ans < 0) ans += mod; 

        return ans ; 
    }
};