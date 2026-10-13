class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size() ; 
        int plus = n/2 + n%2 , minus = n/2 ; 
        for(int i=0 ; i<n ; i++){
            nums[i] = abs(nums[i]) ; 
        }
        sort(nums.begin(),nums.end(),greater<int>()) ; 
        long long ans = 0 ; 
        int i = 0 ;
        while(plus--){
            ans += (nums[i])*nums[i] ; 
            // cout << nums[i] << " " ; 
            i++ ; 
        }
        while(minus--){
            ans -= nums[i]*nums[i] ; 
            i++ ;
            // cout << nums[i] << " " ; 
        }
        return ans ; 
    }
};