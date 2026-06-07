class Solution {
public:
    using ll = long long ; 
    const ll mod = 1e9 + 7 ; 
    ll dp[110][2][2][10] ; 

    int countSteppingNumbers(string low, string high) {
        auto f = [&](auto&& f , int idx , bool tight , bool start , int lastDigit , string s , int n) -> ll{
            if(idx == n) return 1 ; 
            if(dp[idx][tight][start][lastDigit] != -1) return dp[idx][tight][start][lastDigit] ;  
            int limit = (tight) ? s[idx]-'0' : 9 ; 
            ll ans = 0 ; 
            if(start){
                if(lastDigit-1>=0 && lastDigit-1<=limit) ans += f(f,idx+1,(tight) & (lastDigit-1 == limit) , start , lastDigit-1,s,n) ; 
                if(lastDigit+1>=0 && lastDigit+1<=limit) ans += f(f,idx+1,(tight) & (lastDigit+1 == limit) , start , lastDigit+1,s,n) ;
                ans %= mod ; 
            }
            else{
                for(int i=0 ; i<=limit ; i++){
                    bool newTight = (tight) & (limit == i) ; 
                    if(i == 0){
                        ans += f(f,idx+1,newTight , false , i , s,n) ; 
                    }
                    else{
                        ans += f(f,idx+1,newTight , true , i , s , n) ; 
                    }
                    ans %= mod ; 
                }
            }

            return dp[idx][tight][start][lastDigit] = ans%mod ; 
        };

        int n1 = low.size() , n2 = high.size() ; 
        memset(dp,-1,sizeof(dp)) ; 
        ll val1 = f(f,0,1,false,0,low,n1) ; 
        memset(dp,-1,sizeof(dp)) ; 
        ll val2 = f(f,0,1,false,0,high,n2) ;
        
        bool isValid = true ;

        for(int i=1 ; i<n1 ; i++){
            if(abs(low[i-1]-low[i]) != 1){
                isValid = false ; 
                break ; 
            }
        }

        return (val2 - val1 + isValid + mod) % mod ;  
    }   
};