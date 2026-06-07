class Solution {
public:
    using ll = long long ; 
    ll dp[20][2] ; 
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s){
        int len = s.size() ; 

        auto f = [&](auto&& f , int idx , bool tight , string& str , int n) -> ll{
            if(idx + len > n) return 0 ; 
            if(dp[idx][tight] != -1) return dp[idx][tight] ;
            if(idx + len == n){
                int ans = 0 ; 
                if(tight){ 
                    int temp = idx ; 
                    for(int i=0 ; i<len ; i++){
                        if(str[temp] < s[i]){
                            break ; 
                        }
                        else if(str[temp] > s[i]){
                            ans = 1 ; 
                            break ; 
                        }
                        if(i == len-1){
                            ans = 1 ; 
                        }
                        temp++ ; 
                    }
                }
                else ans = 1 ; 
                return ans ; 
            }

            int acutual_bound = (tight) ? (str[idx] - '0') : limit ; 
            int bound = min(limit,acutual_bound) ; 
            
            ll ans = 0 ; 
            for(int i=0 ; i<=bound ; i++){
                bool newTight = (tight) & (acutual_bound == i) ; 
                ans += f(f,idx+1,newTight,str,n) ; 
            }

            return dp[idx][tight] = ans ; 
        };
        start-- ; 
        string s1 = to_string(start) , s2 = to_string(finish) ; 
        int n1 = s1.size() , n2 = s2.size() ; 
        memset(dp,-1,sizeof(dp)) ;
        ll val1 = f(f,0,true,s1,n1) ; 
        memset(dp,-1,sizeof(dp)) ;
        ll val2 = f(f,0,true,s2,n2) ; 

        return val2 - val1 ; 
    }
};