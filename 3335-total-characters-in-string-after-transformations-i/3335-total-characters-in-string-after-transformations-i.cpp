class Solution {
public:
    const int mod = 1e9 + 7 ; 
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();

        vector<int> mp(26,0) ; 
        for (int i = 0; i < n; i++) {
            mp[s[i]-'a']++;
        }

        for(int i = 1; i <= t; i++){
            vector<int> next(26,0);

            for(int c = 'a' ; c<= 'z' ; c++){
                long long freq = mp[c-'a'];

                if(c == 'z'){
                    next['a'-'a'] = (next['a'-'a'] + freq) % mod;
                    next['b'-'a'] = (next['b'-'a'] + freq) % mod;
                } 
                else{
                    char newChar = c + 1;
                    next[newChar-'a'] = (next[newChar-'a'] + freq) % mod;
                }
            }

            mp = move(next);
        }

        long long ans = 0;
        for(int i=0 ; i<26 ; i++){
            ans = (ans + mp[i])%mod ;
        }
        return (int)ans;
    }
};