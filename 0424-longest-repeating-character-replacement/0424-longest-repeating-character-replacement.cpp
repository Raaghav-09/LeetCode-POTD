class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size() ; 
        map<char,int> mp ; 
        int i = 0 , j = 0 ; 
        int ans = 0 ; 
        while(j<n){
            mp[s[j]]++ ; 

            while(true){
                int mx = 0 ; 
                for(auto& [ch,freq] : mp){
                    mx = max(mx,freq) ; 
                }
                int extra = j-i+1-mx ;
                if(extra > k){
                    mp[s[i]]-- ; 
                    i++ ; 
                }
                else break ; 
            }

            ans = max(ans,j-i+1) ; 
            j++ ; 
        }

        return ans ; 
    }
};