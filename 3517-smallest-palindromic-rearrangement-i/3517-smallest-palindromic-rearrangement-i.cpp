class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length() ; 
        map<char,int> mp ;
        for(int i=0 ; i<n ; i++) mp[s[i]]++ ; 
        string ans = "" ; 
        char middle = '0' ; 
        for(auto [x,y] : mp){
            if(y%2==1){
                middle = x ; 
            }
            for(int i=1 ; i<=y/2 ; i++){
                ans+=x ; 
            }
        }
        if(n%2==1){
            string rev = ans ; 
            reverse(rev.begin(),rev.end()) ; 
            ans = ans + middle + rev ; 
        }
        else{
            string rev = ans ; 
            reverse(rev.begin(),rev.end()) ; 
            ans = ans + rev ; 
        }
        return ans; 
    }
};