class Solution {
public:
    using ll = long long ; 
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size() ; 
        ll sum = accumulate(nums.begin(),nums.end(),0LL) ; 
        ll lo = *max_element(nums.begin(),nums.end()) , hi = sum ; 
        // FFFFFFFTTTTTT
        auto check = [&](ll mid) -> bool{
            ll curr = 0 ; 
            int parts = 1 ; 
            bool flag = false; 
            for(int i=0 ; i<n ; i++){
                if(curr + nums[i] <= mid){
                    curr += nums[i] ; 
                }
                else{
                    curr = nums[i] ; 
                    parts++ ; 
                }
                if(parts > k) return false; 
            }
            return parts <= k ; 
        };
        ll ans = hi ; 
        while(lo<=hi){
            ll mid = (lo) + (hi - lo)/2 ; 
            if(check(mid)){
                hi = mid - 1; 
                ans = mid ; 
            }
            else{
                lo = mid + 1 ; 
            }
        }

        return ans ; 
    }
};