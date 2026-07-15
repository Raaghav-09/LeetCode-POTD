class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() ; 

        int pre = 1 , suff = 1 ; 
        int mx = INT_MIN ; 
        for(int i=0 ; i<n ; i++){
            pre *= nums[i] ; 
            suff *= nums[n-1-i] ; 
            mx = max(mx,max(pre,suff)) ; 
            
            if(nums[i] == 0) pre = 1 ; 
            if(nums[n-i-1] == 0) suff = 1 ; 
        }

        return mx ; 
    }
};