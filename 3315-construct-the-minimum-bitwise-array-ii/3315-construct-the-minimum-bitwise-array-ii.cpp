class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> v(n,-1) ; 

        for(int i=0 ; i<n ; i++){

            if(nums[i] == 2 ) continue ; 

            int num = nums[i] ; 
            int count = 0 ; 
            while(num & 1){
                num >>= 1 ;
                count++ ; 
            }

            v[i] = nums[i] - (1 << (count-1)) ; 
        }

        return v ; 
    }
};