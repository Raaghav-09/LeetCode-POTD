class Solution {
public:
    using ll = long long ; 
    ll f(ll digits , bool tight , int limit , string& s , string& suff , vector<vector<ll>>& dp){
        if(dp[digits][tight] != -1) return dp[digits][tight] ; 
        if(digits + suff.size() == s.size()){
            if(tight){
                // MINIMAL CHANGE 1: The suffix just needs to be <= the remaining string. 
                // Also, we must explicitly return 0 if it fails so we don't fall through to the loop.
                string remaining = s.substr(digits);
                if (suff <= remaining) return 1;
                return 0; 
            }
            else{
                return 1 ; 
            }
        }

        // MINIMAL CHANGE 2: Convert char to int properly, and ensure we respect the global limit too.
        int bound = (tight) ? min(limit, s[digits] - '0') : limit ; 

        ll ans = 0 ; 
        for(int i=0 ; i<=bound ; i++){
            // MINIMAL CHANGE 3: Next tight depends on matching the actual string digit, not the clamped `bound`.
            ans += f(digits+1,(tight && (i == (s[digits] - '0'))) , limit , s , suff , dp) ; 
        }

        return dp[digits][tight] = ans ; 
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        // MINIMAL CHANGE 4: If the target suffix itself contains a digit > limit, it's impossible.
        for(char c : s){
            if(c - '0' > limit) return 0;
        }

        int n = s.size() ; 

        auto isValid = [&](ll num) -> bool{
            string t = to_string(num) ; 
            if(t.size() < s.size()) return false ; 
            
            // MINIMAL CHANGE 6: We MUST check if the number itself violates the limit!
            for(char c : t){
                if(c - '0' > limit) return false;
            }

            int j = t.size()-1 ; 
            bool flag = true ; 
            for(int i=n-1 ; i>=0 ; i--){
                if(s[i] != t[j]){
                    flag = false ; 
                    break ; 
                }
                j-- ; 
            }

            return flag ; 
        };

        string s1 = to_string(start) , s2 = to_string(finish) ; 
        vector<vector<ll>> dp1(s1.size()+1 , vector<ll>(2,-1)) ; 
        vector<vector<ll>> dp2(s2.size()+1 , vector<ll>(2,-1)) ; 

        // MINIMAL CHANGE 5: Only run DP if the number is at least as long as the suffix
        ll plus = (s2.size() >= s.size()) ? f(0, 1, limit, s2, s, dp2) : 0; 
        ll minus = (s1.size() >= s.size()) ? f(0, 1, limit, s1, s, dp1) : 0; 

        ll ans = plus - minus + isValid(start); 

        return ans ;
    }
};