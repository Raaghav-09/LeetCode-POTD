class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ; 
        int ans = 0 ; 
        for(int i=0 ; i<n ; i++){
            long long val = 1LL*nums[i]*k ; 
            int r = upper_bound(nums.begin()+i , nums.end() , val) - nums.begin() - i ; 
            ans = max(ans , r ) ; 
        }
        return n - ans ; 
    }
};