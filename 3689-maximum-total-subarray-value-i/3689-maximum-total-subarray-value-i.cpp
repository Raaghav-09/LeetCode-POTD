class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size() ; 
        int mx = 0 , mn = INT_MAX ; 
        for(int i=0 ; i<n ; i++){
            mx = max(mx,nums[i]) ; 
            mn = min(mn,nums[i]) ; 
        }
        long long ans = (long long)(mx-mn)*(long long)(k) ; 
        return ans ; 
    }
};