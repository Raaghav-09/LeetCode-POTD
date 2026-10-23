class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size() ; 

        /*
        a AND b = k 
        only if , a and k != 0 && b and k != 0 
        a and k >= k , and b and k >= k 

        that means (a and k = k) and (b and k = k )

        */
        int combined = -1 ; 
        for(int i=0 ; i<n ; i++){
            if(nums[i] == i){
                continue ; 
            }
            else{
                if(combined == -1){
                    combined = nums[i] ; 
                }
                else{
                    combined &= nums[i] ; 
                }
            }
        }
        if(combined == -1) combined = 0 ;
        return combined ;
    }
};