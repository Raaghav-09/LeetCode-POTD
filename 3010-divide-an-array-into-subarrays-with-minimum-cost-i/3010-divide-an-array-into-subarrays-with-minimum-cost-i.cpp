class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size() ; 
        int mn = 100 , second_mn = 100 ; 
        for(int i=1 ; i<n ; i++){
            if(nums[i] < mn){
                second_mn = mn ; 
                mn = nums[i] ; 
            }
            else if(nums[i] < second_mn){
                second_mn = nums[i] ; 
            }
        }
        if(n <= 3) return accumulate(nums.begin() , nums.end() , 0) ; 
        return nums[0] + mn + second_mn ; 
    }
};