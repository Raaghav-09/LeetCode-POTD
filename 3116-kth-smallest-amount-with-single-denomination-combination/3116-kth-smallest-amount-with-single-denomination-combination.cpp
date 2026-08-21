class Solution {
public:
    using ll = long long ; 
    ll giveMeLcm(ll no1 , ll no2){
        ll gcd = __gcd(no1,no2) ; 
        return (no1/gcd) * no2 ; 
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size() ; 
        /*
        4  8  12  25
        8  16 24  50
        12 24 36  75
        16 32 48  100        
        */
        map<int,vector<ll>> mp ; 
        for(int mask=1 ; mask<(1<<n) ; mask++){
            int no = 0 ; 
            ll lcm = 1 ; 
            for(int i=0 ; i<n ; i++){
                if(((1<<i) & mask )!= 0){
                    lcm = giveMeLcm(lcm,coins[i]) ; 
                    no++ ; 
                }
            }
            mp[no].push_back(lcm) ; 
        }
        auto check = [&](ll mid) -> bool{
            ll cnt = 0 ; 
            bool plus = true ; 
            for(auto& [ele,lcms] : mp){
                for(ll lcm : lcms){
                    if(plus){
                        cnt += mid/lcm ; 
                    }
                    else{
                        cnt -= mid/lcm ; 
                    }
                }
                plus = !plus ; 
            }
            return cnt >= k ; 
        };

        sort(coins.begin(),coins.end()) ; 
        ll low = coins[0] , high = (ll)coins[0]*k ; 
        ll ans = low ; 
        // TTTTTFFFFF
        while(low<=high){
            ll mid = low + (high-low)/2 ; 
            if(check(mid)){
                ans = mid ; 
                high = mid - 1 ;  
            }
            else{
                low = mid + 1 ; 
            }
        }
        return ans ; 
    }
};