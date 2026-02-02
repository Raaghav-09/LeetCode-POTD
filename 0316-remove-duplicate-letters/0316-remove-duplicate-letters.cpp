class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size() ; 

        vector<int> cnt(26,0) ; 
        for(char ch : s) cnt[ch-'a']++ ; 
        set<char> used ; 
        string ans = "" ; 
        for(int i=0 ; i<n ; i++){
            cnt[s[i]-'a']-- ; 

            if(used.find(s[i]) != used.end()) continue ; 

            while(ans.size() && ans.back() > s[i] && cnt[ans.back() - 'a'] > 0 ){
                used.erase(ans.back()) ; 
                ans.pop_back() ; 
            }

            ans.push_back(s[i]) ; 
            used.insert(s[i]) ; 
        }

        return ans ; 
    }
};