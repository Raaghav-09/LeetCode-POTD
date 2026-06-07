class Solution {
public:
    int dp[12][2][2][2048][2] ; 
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n) ; 
        int m = s.size() ; 
        memset(dp,-1,sizeof(dp)) ; 

        auto f = [&](auto&& f , int idx , bool tight , bool start , int mask , bool found) -> int{
            if(idx == m) return found ; 
            if(dp[idx][tight][start][mask][found] != -1) return dp[idx][tight][start][mask][found] ; 
            int limit = (tight) ? s[idx] - '0' : 9 ; 
            int ans = 0 ; 
            for(int i=0 ; i<=limit ; i++){
                bool newTight = (tight) & (i == limit) ; 
                if(start){
                    bool newFound = ((mask >> i) & 1) ; 
                    int newMask = (mask | (1 << i )) ; 
                    ans += f(f,idx+1,newTight,true,newMask,found | newFound) ; 

                }
                else{
                    if(i==0) ans += f(f,idx+1,newTight,false,0,false) ; 
                    else ans += f(f,idx+1,newTight,true,1<<i,false) ; 
                }
            }

            return dp[idx][tight][start][mask][found] = ans ; 
        };

        return f(f,0,1,0,0,0) ; 
    }
};