class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = target.size() ; 
        map<char,int> mp ; 
        for(auto ch : s) mp[ch]++ ; 

        string ans = "" ; 
        int i=0 ; 
        int notFound = false;

        while(!notFound && i<n){
            if(mp.count(target[i])){
                ans += target[i] ; 
                mp[target[i]]-- ; 
                if(mp[target[i]] == 0) mp.erase(target[i]) ; 
                i++ ; 
            }
            else{
                notFound = true ; 
                // i++ ;                 // FIX 1
            }
        }

        if(i<n){
            auto it = mp.upper_bound(target[i]) ; 

            if(it != mp.end()){
                char ch = it->first ; 
                ans += ch; 

                mp[ch]-- ; 
                if(mp[ch] == 0) mp.erase(ch) ; 

                for(auto [cha,freq] : mp){
                    while(freq--) ans += cha ;     // FIX 2
                }

                return ans;
            }
            else{
                
                for(int j = i - 1; j >= 0; j--) {

                    char old = ans.back();
                    ans.pop_back();
                    mp[old]++;

                    auto it = mp.upper_bound(target[j]);

                    if(it != mp.end()) {

                        char ch = it->first;
                        ans += ch;

                        mp[ch]--;
                        if(mp[ch] == 0) mp.erase(ch);

                        for(auto [cha, freq] : mp) {
                            while(freq--)
                                ans += cha;
                        }

                        return ans;
                    }
                }

                return "";              // FIX 3
            }
        }
        else{
            /*
                s can exactly form target.

                So find the immediately next
                lexicographical permutation.
            */

            if(next_permutation(ans.begin(),ans.end())){
                return ans ;
            }
            else return "" ;
        }

        return ans ; 
    }
};