class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n) ; 
        long long ans = 0 ; 
        long long sum = 0 ; 
        for(auto ch : s){
            int no = ch - '0' ;
            if(no != 0){
                sum += no ; 
                ans *= 10 ; 
                ans += no ; 
            }
        }

        return ans * sum ; 
    }
};