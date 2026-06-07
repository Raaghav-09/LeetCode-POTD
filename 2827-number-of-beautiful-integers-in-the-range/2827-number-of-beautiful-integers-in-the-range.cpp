class Solution {
public:
    using ll = long long ; 
    ll dp[12][2][2][12][12][25] ; 
    int numberOfBeautifulIntegers(int low, int high, int k) {
        
        memset(dp,-1,sizeof(dp)) ; 
        auto f = [&](auto&& f , int idx , bool tight , bool start , int even , int odd , int num , string& s , int n) -> ll{
            if(idx == n){
                if(even == odd && num%k == 0) return 1 ; 
                else return 0 ; 
            }
            if(dp[idx][tight][start][even][odd][num] != -1) return dp[idx][tight][start][even][odd][num] ; 
            int limit = (tight) ? s[idx] - '0' : 9 ; 
            ll ans = 0 ; 
            for(int i=0 ; i<=limit ; i++){
                bool newTight = (tight) & (i == limit) ; 
                if(i == 0){
                    if(start) ans += f(f,idx+1,newTight,start,even+1,odd,(num*10)%k,s,n) ; 
                    else ans += f(f,idx+1,newTight,start,even,odd,num,s,n) ; 
                }
                else{
                    int o = (i%2) , e = 1 - o ;
                    ans += f(f,idx+1,newTight,true,even+e,odd+o,(num*10+i) % k , s , n) ; 
                }
            }

            return dp[idx][tight][start][even][odd][num] = ans ; 
        };

        low-- ; 
        string s1 = to_string(low) , s2 = to_string(high) ; 
        int n1 = s1.size() , n2 = s2.size() ; 

        ll val1 = f(f,0,1,0,0,0,0,s1,n1) ; 
        memset(dp,-1,sizeof(dp)) ; 
        ll val2 = f(f,0,1,0,0,0,0,s2,n2) ; 

        return val2 - val1 ; 
    }
};