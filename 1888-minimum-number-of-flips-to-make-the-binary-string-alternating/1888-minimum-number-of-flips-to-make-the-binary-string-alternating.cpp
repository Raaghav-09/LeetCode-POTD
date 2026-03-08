class Solution {
public:
    int minFlips(string s) {
        int n = s.size() ; 
        
        string t = s + s ; 

        // considering starting as 0 
        int ans = INT_MAX ;
        int op = 0 ;  
        for(int i=0 ; i<n ; i++){
            if(i%2 == 0 && t[i] == '1'){
                op++ ; 
            }
            else if(i%2 == 1 && t[i] == '0'){
                op++ ; 
            }
        }

        ans = min(ans , op) ; 

        for(int i=n ; i<2*n ; i++){
            if(i%2 == 0 && t[i] == '1'){
                op++ ; 
            }
            else if(i%2 == 1 && t[i] == '0'){
                op++ ; 
            }
            int j = i-n ; 
            if(j%2 == 0 && t[j] == '1'){
                op-- ; 
            }
            else if(j%2 == 1 && t[j] == '0'){
                op-- ; 
            }
            ans = min(ans,op) ; 
        }


        // same for starting with 1 
        int op2 = 0 ; 
        for(int i=0 ; i<n ; i++){
            if(i%2 == 0 && t[i] == '0'){
                op2++ ; 
            }
            else if(i%2 == 1 && t[i] == '1'){
                op2++ ; 
            }
        }

        ans = min(ans,op2) ; 
        for(int i=n ; i<2*n ; i++){
            if(i%2 == 0 && t[i] == '0'){
                op2++ ; 
            }
            else if(i%2 == 1 && t[i] == '1'){
                op2++ ; 
            }
            int j = i-n ; 
            if(j%2 == 0 && t[j] == '0'){
                op2-- ; 
            }
            else if(j%2 == 1 && t[j] == '1'){
                op2-- ; 
            }
            ans = min(ans,op2) ; 
        }

        return ans ; 
        
    }
};