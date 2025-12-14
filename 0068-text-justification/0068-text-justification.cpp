class Solution {
public:
    string applyEvenly(string& s , int maxWidth){
        int n = s.size() ; 
        vector<string> words ; 
        int i=0 ; 
        string str = "" ; 
        int total = 0 ; 
        while(i<n){
            if(s[i]==' '){
                if(str!=""){
                    words.push_back(str) ; 
                    str = "" ; 
                }
            }
            else{
                str += s[i] ; 
                total++ ; 
            }
            i++ ; 
        }
        if(str!="") words.push_back(str) ; 
        if(words.size()==1){
            string ans = words[0] ; 
            while(ans.size()!=maxWidth) ans += ' ' ; 
            return ans ; 
        }
        int div = words.size() - 1 ; 
        int spaces = (maxWidth - total) ; 
        int between = spaces/div ; 
        int rem = spaces % div ; 

        string ans = "" ; 
        for(int i=0 ; i<=div ; i++){
            ans += words[i] ; 
            if(i==div) break ; 
            int t = between ; 
            while(t--) ans += ' ' ; 
            if(rem){
                ans += ' ' ; 
                rem-- ;
            }
        }
        return ans ; 

    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size() ; 
        vector<string> ans ; 
        string str = "" ; 
        for(int i=0 ; i<n ; i++){
            if(str.size()+words[i].size() <= maxWidth){
                str += words[i] ; 
                if(str.size()<maxWidth) str+= " " ; 
            }
            else{
                ans.push_back(str) ; 
                str = words[i] ; 
                if(str.size()<maxWidth) str += " " ;
            }
        }
        if(str!="") ans.push_back(str) ; 
        int m = ans.size() ; 
        for(int i=0 ; i<m-1 ; i++){
            string s = applyEvenly(ans[i],maxWidth) ; 
            ans[i] = s ;
        }
        string s = ans.back() ; 
        while(s.size()!=maxWidth) s += ' ' ; 
        ans.back() = s ; 
        return ans ; 
    }
};