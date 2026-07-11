class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size() ; 

        map<int,long long> mp ; 
        int xr = 0 ; 
        mp[xr]++ ; 
        for(int i=0 ; i<n ; i++){
            xr ^= nums[i] ; 
            mp[xr]++ ; 
        }   

        long long ans = 0 ; 
        for(auto& [ele,freq] : mp){
            ans += ((freq)*(freq-1))/2 ; 
        }

        return ans ; 
    }
};