class Solution {
public:
    int minOperations(string s) {
        int n = s.size() ; 

        int op1 = 0 , op2 = 0 ; 

        for(int i=0 ; i<n ; i++){
            if(i%2 == 0){
                if(s[i] == '0') op1++ ; 
                else op2++ ; 
            }
            else{
                if(s[i] == '0') op2++ ; 
                else op1++ ; 
            }
        }

        return min(op1 , op2) ; 
        
    }
};