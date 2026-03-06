class Solution {
public:
    bool checkOnesSegment(string s) {
        bool occur = false ; 
        int n = s.length() ; 
        for(int i=0 ; i<n ; i++){
            if(s[i] == '1' && occur) return false ; 
            while(i<n && s[i] == '1'){
                occur = true ; 
                i++ ; 
            }
        }
        return true ; 
    }
};