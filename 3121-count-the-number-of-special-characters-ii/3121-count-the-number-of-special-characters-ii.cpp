class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size() ; 

        map<char,vector<int>> mp ; 
        for(int i=0 ; i<n ; i++){
            mp[word[i]].push_back(i) ; 
        }
        int ans = 0 ; 
        for(char ch = 'a' ; ch<='z' ; ch++){
            char corr = ch - 97 + 65 ; 
            if(mp.find(ch) != mp.end() && mp.find(corr) != mp.end()){
                if(mp[ch].back() < mp[corr].front()) ans++ ; 
            }
        }

        return ans ; 
    }
};