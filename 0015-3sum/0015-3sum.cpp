class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ; 
        sort(nums.begin(),nums.end()) ; 
        
        vector<vector<int>> ans ; 
        int i = 0 ; 
        while(i<n-2){
            int j = i+1 , k = n-1 ; 
            int target = -1*nums[i] ; 
            while(j<k){
                if((nums[j] + nums[k]) > target){
                    k-- ; 
                }
                else if((nums[j] + nums[k]) < target){
                    j++ ; 
                }
                else{
                    // (nums[j] + nums[k]) == target
                    ans.push_back({nums[i],nums[j],nums[k]}) ; 
                    int val1 = nums[j] , val2 = nums[k] ; 
                    while(j<n && val1 == nums[j]) j++ ; 
                    while(k>=0 && val2 == nums[k]) k-- ; 
                }
            }
            int val = nums[i] ; 
            while(i<n-2 && nums[i] == val) i++ ; 
        }

        return ans ; 
    }
};