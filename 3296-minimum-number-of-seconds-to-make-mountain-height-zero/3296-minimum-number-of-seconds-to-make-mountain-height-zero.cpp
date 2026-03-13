class Solution {
public:
    using ll = long long ; 
    ll check(ll mid , vector<int>& workerTimes  , int mountainHeight ){
        int n = workerTimes.size() ; 
        
        int h = 0 ; 
        for(int i=0 ; i<n ; i++){
            ll sum = mid/workerTimes[i] ; 
            // sum = (h)*(h+1)/2 
            // h2 + h - 2*sum = 0 => h = (-1 + sqrt(1 + 8*sum))/2

            ll dec = (-1 + sqrt(1 + 8.0*sum))/2 ; 
            h += dec ; 
            if(h >= mountainHeight) return true ;
        }

        return h >= mountainHeight ;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size() ; 

        ll low = 0 , high = 1e17 ; 
        ll ans = high ; 

        for(int iteration = 0 ; iteration<=70 ; iteration++){
            ll mid = (low+high)/2 ; 

            if(check(mid , workerTimes , mountainHeight)){
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