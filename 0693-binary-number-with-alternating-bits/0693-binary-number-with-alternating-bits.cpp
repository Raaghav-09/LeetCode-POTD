class Solution {
public:
    bool hasAlternatingBits(int n) {
        char prev = ' ' ;  
        while(n){
            if(prev == ' '){
                prev = n%2 + '0' ; 
            }
            else{
                if(prev == n%2 + '0') return false ; 
                else prev = n%2 + '0' ; 
            }
            n/=2 ; 
        }
        return true ; 
    }
};