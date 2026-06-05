class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size() ; 

        int sum = accumulate(nums.begin(),nums.end(),0) ; 
        if(sum % 2 == 1) return false; 

        int target = sum/2 ; 

        vector<bool> dp(target+1,false) ; 
        dp[0] = true ;
        if(nums[0] <= target) dp[nums[0]] = true;  
        for(int i=1 ; i<n ; i++){
            for(int s = target; s >= nums[i]; s--){
                dp[s] = dp[s] | dp[s - nums[i]];
            }
        }

        return dp[target] ;
    }
};