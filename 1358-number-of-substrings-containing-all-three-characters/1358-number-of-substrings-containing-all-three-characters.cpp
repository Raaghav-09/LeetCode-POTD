class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size() ; 

        map<int,int> mp ; 
        int ans = 0 ; 
        int i = 0 , j = 0 ; 
        while(i<n){
            while(j<n && !(mp['a'] > 0 && mp['b']>0 && mp['c']>0)){
                mp[s[j]]++ ; 
                j++ ; 
            }
            if(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
                ans += (n-j+1); 
            }
            mp[s[i]]-- ; 
            i++ ; 
        }
        return ans ; 
    }
};