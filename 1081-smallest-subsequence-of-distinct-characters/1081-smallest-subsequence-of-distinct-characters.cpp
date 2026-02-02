class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size() ; 

        map<char,int> mp ; 
        for(char ch : s) mp[ch]++ ; 
        
        set<char> used ; 

        stack<char> st ; 
        for(int i=0 ; i<n ; i++){
            mp[s[i]]-- ; 

            if(used.find(s[i]) != used.end()) continue ; 

            while(st.size() && st.top()>=s[i] && mp[st.top()]>0){
                used.erase(st.top()) ; 
                st.pop() ; 
            }

            st.push(s[i]) ; 
            used.insert(s[i]) ; 
        }

        string ans = "" ; 

        while(st.size()){
            ans = st.top() + ans ; 
            st.pop() ; 
        }

        return ans ; 
    }
};