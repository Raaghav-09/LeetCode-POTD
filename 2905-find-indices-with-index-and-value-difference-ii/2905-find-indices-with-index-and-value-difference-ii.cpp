class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size() ; 

        // n*log(n)
        // multiset<pair<int,int>> mul ; 
        // for(int j=indexDifference ; j<n ; j++){
        //     // j-i>= iD => i <= j - iD 
        //     mul.insert({nums[j-indexDifference] , j-indexDifference }) ; 
        //     if(abs(nums[j] - mul.begin()->first) >= valueDifference){
        //         return {mul.begin()->second , j} ; 
        //     }
        //     else if(abs(nums[j] - mul.rbegin()->first) >= valueDifference ){
        //         return {mul.rbegin()->second , j} ; 
        //     }
        // }

        // return {-1,-1} ; 

        // n
        // the largest and smallest only matters 
        int mnIdx = -1 , mxIdx = -1 ; 
        for(int j=indexDifference ; j<n ; j++){
            int ind = j - indexDifference ; 
            if(mnIdx == -1 && mxIdx == -1){
                mxIdx = ind ;
                mnIdx = ind ;
            }
            else{
                if(nums[ind] > nums[mxIdx]){
                    mxIdx = ind ; 
                }
                if(nums[ind] < nums[mnIdx]){
                    mnIdx = ind ; 
                }
            }

            if(abs(nums[j] - nums[mnIdx]) >= valueDifference){
                return {mnIdx , j} ; 
            }
            else if(abs(nums[j] - nums[mxIdx]) >= valueDifference){
                return {mxIdx , j} ; 
            }
        }

        return {-1,-1} ; 
    }
};