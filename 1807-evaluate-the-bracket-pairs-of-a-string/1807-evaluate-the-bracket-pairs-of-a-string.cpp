class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size() ; 
        map<string,string> mp ; 
        for(auto v : knowledge){
            mp[v[0]] = v[1] ; 
        }

        int i=0 ; 
        string ans = "" ; 
        while(i<n){
            if(s[i] == '('){
                i++ ; 
                string key = "" ; 
                while(i<n && s[i]!= ')'){
                    key += s[i] ; 
                    i++ ; 
                }
                if(s[i] == ')'){
                    i++ ; 
                }
                if(mp.count(key)){
                    ans += mp[key] ; 
                }
                else ans += '?' ; 
            }
            else{
                ans += s[i] ; 
                i++ ; 
            }
        }

        return ans ; 
    }
};