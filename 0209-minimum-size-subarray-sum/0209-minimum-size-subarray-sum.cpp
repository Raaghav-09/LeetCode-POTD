class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size() ; 

        int i = 0 , j = 0 ; 
        int curr = 0 ; 

        int ans = n+1 ; 
        while(i<n){
            while(j<n && curr < target){
                curr += nums[j] ; 
                j++ ; 
            }
            if(curr >= target) ans = min(ans,(j-i)) ; 
            curr -= nums[i] ; 
            i++ ; 
        }
        if(ans == n+1) ans = 0 ; 
        return ans ; 
    }
};