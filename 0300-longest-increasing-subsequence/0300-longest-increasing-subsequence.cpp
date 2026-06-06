class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ; 

        // memset(dp,-1,sizeof(dp)) ;
        // auto f = [&](auto&& f ,int idx , int lastIdx ) -> int{
        //     if(idx > n) return 0 ; 
        //     if(dp[idx][lastIdx] != -1) return dp[idx][lastIdx] ; 
        //     int len = 0 ; 
        //     if(lastIdx == 0 || (nums[idx-1] > nums[lastIdx-1])){
        //         len = 1 + f(f,idx+1,idx) ; 
        //     }
        //     len = max(len , f(f,idx+1,lastIdx)) ; 
        //     return len ; 
        //     return dp[idx][lastIdx] = len ; 
        // };
        // return f(f,1,0) ; 

        /*
        dp[i][j] -> lenght of the lis with last element as nums[j]
        dp[i][j] = max(dp[i][k] + 1 ); where k is from 0 to j-1
        */
        vector<int> dp(n,1) ; 
        int ans = 1 ; 
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],1+dp[j]) ; 
                }
                ans = max(ans,dp[i]) ; 
            }
        }
        return ans ; 
    }
};