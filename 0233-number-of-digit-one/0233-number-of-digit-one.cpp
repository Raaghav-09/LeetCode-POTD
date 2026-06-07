class Solution {
public:
    int dp[11][2][11] ; 
    int countDigitOne(int n) {
        
        auto f = [&](auto&& f , int idx , bool tight , int cnt , string& s , int len) -> int{
            if(idx == len) return cnt ; 
            if(dp[idx][tight][cnt] != -1) return dp[idx][tight][cnt] ; 

            int limit = (tight) ? s[idx] - '0' : 9 ; 
            int ans = 0 ; 
            for(int i=0 ; i<=limit ; i++){
                bool newTight = (tight) & (i == limit) ; 
                if(i == 1) ans += f(f,idx+1,newTight , cnt + 1 , s , len) ; 
                else ans += f(f,idx+1,newTight , cnt , s , len) ; 
            }

            return dp[idx][tight][cnt] = ans ; 
        };
        
        string s = to_string(n) ; 
        int len = s.size() ; 
        memset(dp,-1,sizeof(dp)) ; 
        return f(f,0,true,0,s,len) ; 
    }
};