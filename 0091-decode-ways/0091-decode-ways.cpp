class Solution {
public:
    using ll = long long ; 
    const ll mod = LLONG_MAX ; 
    
    int numDecodings(string s) {
        int n = s.size() ;

        if(s[0] == '0') return 0;

        vector<vector<ll>> dp(n+1, vector<ll>(10, 0)) ; 
        vector<ll> dpp(n+1) ; 
        
        if(s[0] == '*'){
            ll sum = 0 ; 
            for(int i=1 ; i<=9 ; i++){
                dp[0][i]++ ; 
                sum += dp[0][i] ; 
            }
            dpp[0] = sum ; 
        }
        else{
            dp[0][s[0]-'0']++ ; 
            dpp[0] = dp[0][s[0]-'0'] ; 
        }
        
        for(int i=1 ; i<n ; i++){
            if(s[i] == '*'){
                ll sum = 0 ; 
                for(int j=1 ; j<=9 ; j++){
                    ll ways = 0;
                    if(j<=6){
                        ways = dpp[i-1] + dp[i-1][1] + dp[i-1][2] ; 
                    }
                    else{
                        ways = dpp[i-1] + dp[i-1][1] ;
                    }
                    dp[i][j] = dpp[i-1] % mod ; 
                    sum = (sum + ways) % mod ; 
                }
                dpp[i] = sum ; 
            }
            else if(s[i]<='6'){
                ll ways = ((s[i] == '0') ? 0 : dpp[i-1]) + dp[i-1][1] + dp[i-1][2] ; 
                dp[i][s[i]-'0'] = ((s[i] == '0') ? 0 : dpp[i-1]) % mod; 
                dpp[i] = ways % mod ; 
            }
            else{
                ll ways = dpp[i-1] + dp[i-1][1] ;
                dp[i][s[i]-'0'] = dpp[i-1] % mod ; 
                dpp[i] = ways % mod ; 
            }
        }

        return dpp[n-1] % mod ;  
    }
};