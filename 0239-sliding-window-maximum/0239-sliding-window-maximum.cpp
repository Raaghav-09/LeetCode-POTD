class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size() ; 
        vector<int> ans ;
        map<int , int > mp ; 
        int i=0 , j = 0 ; 
        while(j<k){
            mp[nums[j]]++ ; 
            j++ ; 
        }
        ans.push_back(mp.rbegin()->first) ; 
        while(j<n){
            mp[nums[j]]++ ; 
            mp[nums[i]]-- ; 
            if(mp[nums[i]] == 0) mp.erase(nums[i]) ; 
            i++ ; 
            j++ ; 
            ans.push_back(mp.rbegin()->first) ; 
        }
        return ans ; 
    }
};