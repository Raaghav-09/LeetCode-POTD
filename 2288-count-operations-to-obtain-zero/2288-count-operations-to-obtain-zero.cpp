class Solution {
public:
    int countOperations(int num1, int num2) {
        long long op = 0 ; 
        while(num1>=1 && num2>=1){
            op++ ; 
            if(num1>=num2){
                num1 -= num2 ; 
            }
            else{
                num2 -= num1 ; 
            }
        }
        return op  ; 
    }
};