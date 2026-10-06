class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length() ; 
        stack<char> left ; 
        int steps = 0; 
        for(int i=0 ; i<n ; i++){
            if(s[i]=='(') left.push(s[i]) ; 
            else if(s[i]==')'){
                if(left.size()>0) left.pop() ; 
                else steps++ ;
            }
        }
        steps+=left.size() ; 
        return steps ; 
    }
};