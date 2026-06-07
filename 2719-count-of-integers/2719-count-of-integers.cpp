class Solution {
public:
    using ll = long long ; 
    ll dp[25][220][2] ; 
    const ll mod = 1e9 + 7 ; 
    int count(string num1, string num2, int min_sum, int max_sum) {
        int n1 = num1.size() , n2 = num2.size() ; 

        auto f = [&](auto&& f , int idx , int currSum , bool tight , string& s , int n) -> ll{
            if(currSum > max_sum) return 0 ; 
            if(idx == n){
                if(currSum >= min_sum) return 1 ; 
                else return 0 ; 
            }

            if(dp[idx][currSum][tight] != -1) return dp[idx][currSum][tight] ; 

            int limit = (tight) ? s[idx] - '0' : 9 ; 
            ll ans = 0 ; 
            for(int i=0 ; i<=limit ; i++){
                ans += f(f,idx+1,currSum + i , (tight) & (i == limit) , s , n) ; 
                ans %= mod ; 
            }

            return dp[idx][currSum][tight] = ans ; 
        };

        memset(dp,-1,sizeof(dp)) ; 
        ll large = f(f,0,0,1,num2,n2) ; 
        memset(dp,-1,sizeof(dp)) ; 
        ll small = f(f,0,0,1,num1,n1) ; 
        
        int sum = 0 ; 
        for(auto& ch : num1) sum += ch-'0' ; 
        if(sum >= min_sum && sum <= max_sum) small-- ; 

        return (large - small + mod) % mod ;
    }
};