class Solution {
public:
    int sum ; 
    int f(vector<int>& nums , int target , int idx , vector<vector<int>>& dp){
        int n = nums.size() ; 
        if(idx>=n){
            if(target==0) return 1 ;  
            return 0 ; 
        }
        if(target>sum || target+sum<0) return 0  ; 
        if(dp[idx][sum+target]!=-1) return dp[idx][sum+target] ; 

        int plus = f(nums,target-nums[idx],idx+1,dp) ;
        int minus = f(nums,target+nums[idx],idx+1,dp) ; 

        return dp[idx][sum+target] = plus + minus ; 
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size() ; 
        sum = accumulate(nums.begin(),nums.end(),0) ;
        if(target>sum) return 0 ; 
        vector<vector<int>> dp(n,vector<int>(2*sum+1,-1)) ;  
        int ans = f(nums,target,0,dp) ; 
        return ans ; 
    }
};