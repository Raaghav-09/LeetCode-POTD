class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size() ; 

        unordered_map<int,int> mp ; 

        mp[0] = 1 ; 
        int sum = 0 ; 
        int ans = 0 ; 
        for(int i=0 ; i<n ; i++){
            sum += nums[i] ; 
            if(k != 0){
                int en1 = sum - k ; 
                ans += mp[en1] ; 
            }
            else{
                ans += mp[sum] ; 
            }
            mp[sum]++ ; 
        }

        return ans ; 
    }
};