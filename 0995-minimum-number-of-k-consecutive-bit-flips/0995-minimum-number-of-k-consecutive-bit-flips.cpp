class Solution {
public:
    // 1 1 1 1 0 0 0  k = 3 => n - k + 1 
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size() ; 

        vector<int> prefix(n,0) ; 
        int totalOp = 0 ; 

        for(int i=0 ; i<n ; i++){
            int op = totalOp - ((i-k >= 0) ? prefix[i-k] : 0 ) ; 
            int currState = (nums[i] + (op%2)) % 2 ; 
            if(currState == 0 && i > n - k) return -1 ;

            if(currState == 0){
                totalOp++ ; 
                if(i == 0) prefix[i] = 1 ; 
                else prefix[i] = prefix[i-1] + 1 ; 
            }
            else if(i != 0){
                prefix[i] = prefix[i-1] ; 
            }
        }
        return totalOp ; 
    }
};