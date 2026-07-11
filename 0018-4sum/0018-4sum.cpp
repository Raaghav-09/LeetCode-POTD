class Solution {
public:
    using ll = long long ; 
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size() ; 
        sort(nums.begin(),nums.end()) ; 
        vector<vector<int>> ans ; 
        int i = 0 ; 
        while(i<n-3){
            int j = i+1 ; 
            while(j<n-2){
                int k1 = j+1 , k2 = n-1 ; 
                ll t = (ll)target - (ll)nums[i] - (ll)nums[j] ; 
                while(k1 < k2){
                    if((nums[k1] + nums[k2]) > t){
                        k2-- ; 
                    }
                    else if((nums[k1] + nums[k2]) < t){
                        k1++ ; 
                    }
                    else{
                        // nums[k1] + nums[k2] == t
                        ans.push_back({nums[i],nums[j],nums[k1],nums[k2]}) ; 
                        int val1 = nums[k1] , val2 = nums[k2] ; 
                        while(k1<n && val1 == nums[k1]) k1++ ; 
                        while(k2>=0 && val2 == nums[k2]) k2-- ; 
                    }
                }
                int val = nums[j] ;
                while(j<n-2 && val == nums[j]) j++ ; 
            }
            int val = nums[i] ; 
            while(i<n-3 && val == nums[i]) i++ ; 
        }

        return ans ; 
    }
};