class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size() ; 
        map<int,int> mp ; 
        int xr = 0 ; 
        for(int i=0 ; i<n ; i++){
            mp[nums[i]]++ ; 
            xr ^= nums[i] ; 
        }

        if(mp.size() == 1 && nums[0] == 0) return 0 ; 
        if(xr != 0) return n ; 
        return n-1 ; 
    }
};