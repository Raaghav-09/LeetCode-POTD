class Solution {
public:
    using ll = long long ; 
    long long maxRunTime(int n, vector<int>& batteries){
        int m = batteries.size() ; 
        /*

        */  
        ll sum = accumulate(batteries.begin(),batteries.end(),0LL) ; 
        auto isPossible = [&](ll mid) -> bool{
            ll cnt = 0 ; 
            for(int i=0 ; i<m ; i++){
                cnt += min((ll)batteries[i], mid) ; 
            }

            return cnt >= n*mid ; 
        };

        ll low = 0 , high = 1e14 ; 
        ll ans = low ; 
        // TTTTTFFFFF
        while(low<=high){
            ll mid = (low + high)/2 ; 

            if(isPossible(mid)){
                ans = mid ; 
                low = mid + 1 ; 
            }
            else{
                high = mid - 1 ; 
            }
        }

        return ans ; 
    }
};