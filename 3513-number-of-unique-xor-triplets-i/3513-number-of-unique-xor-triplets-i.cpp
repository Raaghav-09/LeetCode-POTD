class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size() ; 
        if(n<3) return n ; 
        int digit = log2(n) ; 
        return pow(2,digit+1) ; 
    }
};