class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size() ; 

        vector<bool> ans(n) ;
        int curr = 0 ; 
        for(int i=0 ; i<n ; i++){
            curr = (curr%5)*2 + nums[i] ; 
            if(curr%5==0) ans[i] = true ; 
            else ans[i] = false ; 
        }

        return ans ; 
    }
};