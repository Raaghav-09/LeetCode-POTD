class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size() ; 
        vector<int> ans ; 
        multiset<int> mul ; 
        for(int i=0 ; i<k ; i++){
            mul.insert(nums[i]) ; 
        }
        ans.push_back(*mul.rbegin()) ; 
        for(int i=k ; i<n ; i++){
            mul.insert(nums[i]) ; 
            mul.erase(mul.find(nums[i-k])) ; 
            ans.push_back(*mul.rbegin()) ; 
        }

        return ans ; 
    }
};