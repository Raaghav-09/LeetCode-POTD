class Solution {
private:
    int minOp(int target, vector<int>& nums , vector<bool>& taken){
        int n = nums.size() ; 
        int ans = 0 ; 

        int j=0 ; 
        while(j<n){
            if(!taken[j]){
                j++ ; 
                continue ; 
            }

            int st = j ; 
            int all = nums[j] ; 
            while(j<n && taken[j] && ((all & target) != 0)){
                all &= nums[j] ; 
                j++ ; 
            }

            if((all & target) == 0) ans += (j-st-1) ; 
            else ans += (j-st) ; 
        }

        return ans ; 
    }

public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        int n = nums.size() ; 

        int rev_ans = 0 ; 
        int ans = 0 ;

        for(int bit = 29 ; bit>=0 ; bit--){
            int rev_ans_with_curr_bit = rev_ans | (1<<bit) ; 

            vector<bool> taken(n,false) ; 

            for(int i=0 ; i<n ; i++){
                if((nums[i] & rev_ans_with_curr_bit) == 0) continue ; 
                taken[i] = 1 ; 
            }

            if(minOp(rev_ans_with_curr_bit,nums,taken) <= k){
                rev_ans = rev_ans_with_curr_bit ;
            }
            else{
                ans |= (1<<bit) ; 
            }
        }

        return ans ; 
    }
};