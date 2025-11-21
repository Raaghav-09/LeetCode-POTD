class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length() ; 
        int ans = 0 ; 
        unordered_map<char,pair<int,int>> m ; 
        for(int i=0 ; i<n ; i++){
            if(m.find(s[i])==m.end()){
                m[s[i]].first = i ; 
            }
            m[s[i]].second = i ; 
        }
        for(auto p : m){
            int start = p.second.first , end = p.second.second ; 
            if(end-start<=1) continue ; 
            unordered_set<char> uniqueChars ; 
            for(int i=start+1 ; i<=end-1 ; i++){
                uniqueChars.insert(s[i]) ; 
            } 
            ans+=uniqueChars.size() ; 
        }
        return ans ; 
    }
};