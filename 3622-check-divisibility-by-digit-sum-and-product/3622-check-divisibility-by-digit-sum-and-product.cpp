class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0; 
        int temp = n ; 
        int p = 1 ; 
        while(temp){
            int ld = temp % 10 ;
            p *= ld ; 
            sum += ld ; 
            temp /= 10 ; 
        }
        return n % (sum+p) == 0 ; 
    }
};