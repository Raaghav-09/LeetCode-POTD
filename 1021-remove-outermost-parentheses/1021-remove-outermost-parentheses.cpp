class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length() ; 

        string ans = "" ; 

        int o = 0 ; 
        int curr = 0 ; 
        for(int i=0 ; i<n ; i++){
            if(o == 0){
                o = 1 ; 
                curr = 0 ; 
            }
            else{
                if(s[i] == '(') curr++ ; 
                else curr-- ;
                if(curr >= 0){
                    ans += s[i] ; 
                }
                if(curr == -1){
                    o = 0 ; 
                }
            }
        }

        return ans ;
    }
};