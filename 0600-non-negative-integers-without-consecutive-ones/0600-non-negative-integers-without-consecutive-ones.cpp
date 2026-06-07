class Solution {
public:
    int dp[100][2] ; 
    int findIntegers(int n){
        int temp = n ; 
        string s = "" ; 
        while(temp){
            if(temp%2) s += '1' ; 
            else s += '0' ; 
            temp/=2 ; 
        }
        reverse(s.begin(),s.end()) ;

        auto f = [&](auto&& f , int idx , bool tight , string& str , int len) -> int{
            if(idx >= len){
                return 1 ; 
            }
            if(dp[idx][tight] != -1) return dp[idx][tight] ; 
            int bound = (tight) ? (str[idx] - '0') : 1 ; 
            int ans = 0 ; 
            for(int i=0 ; i<=bound ; i++){
                bool newTight = (tight) & (i==bound) ; 
                if(i == 0) ans += f(f,idx+1,newTight , str , len) ; 
                if(i == 1){
                    bool nextTight = newTight && (idx + 1 < len && str[idx + 1] == '0');
                    ans += f(f,idx+2, nextTight , str , len) ;
                }
            }

            return dp[idx][tight] = ans ; 
        };

        memset(dp,-1,sizeof(dp)); 
        int len = s.size() ; 
        return f(f,0,1,s,len) ; 
    }
};