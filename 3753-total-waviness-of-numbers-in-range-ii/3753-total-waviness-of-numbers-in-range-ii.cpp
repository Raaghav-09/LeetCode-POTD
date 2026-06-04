// class Solution {
// public:
//     using ll = long long ; 
//     ll solve(ll num){
//         string s = to_string(num) ; 
//         int m = s.size() ; 
//         auto f = [&](auto&& f , bool tight , bool start , int digit , int inc , int idx) -> ll{
//             if(idx == m){
//                 return 0 ; 
//             }
//             int bound = (tight) ? s[idx] - '0' : 9 ; 
//             int ways = 0 ; 
//             for(int i=0 ; i<=bound ; i++){
//                 if(!start){
//                     if(i == 0) ways += f(f,(tight) & (i == (s[idx] - '0')), 0 , i , 0 , idx+1) ; 
//                     else ways += f(f,(tight) & (i == (s[idx] - '0')), 1 , i , 0 , idx+1) ;
//                 }
//                 else if(i == digit){
//                     ways += f(f,(tight) & (i == (s[idx] - '0')) , start , i , 0 , idx+1) ; 
//                 }
//                 else if(inc == 1){ // increasing
//                     if(i < digit) ways += 1 + f(f,(tight) & (i == (s[idx] - '0')) , start , i , 2 , idx+1 ) ; 
//                     else ways += f(f,(tight) & (i == (s[idx] - '0')) , start , i , 1 , idx+1) ; 
//                 }
//                 else if(inc == 2){ // decreasing
//                     if(i < digit) ways += f(f,(tight) & (i == (s[idx] - '0')) , start , i , 2 , idx+1 ) ; 
//                     else ways += 1 + f(f,(tight) & (i == (s[idx] - '0')) , start , i , 1 , idx+1) ; 
//                 }
//                 else{// inc = 0 -> equal
//                     if(i < digit) ways += f(f,(tight) & (i == (s[idx] - '0')) , start , i , 2 , idx+1 ) ; 
//                     else ways += f(f,(tight) & (i == (s[idx] - '0')) , start , i , 1 , idx+1) ; 
//                 }

//             }
//             return ways ; 
//         };

//         return f(f,1,0,0,0,0) ; 
//     }
//     long long totalWaviness(long long num1, long long num2) {
//         return solve(num2) - solve(num1-1) ; 
//     }
// };

class Solution {
public:
    using ll = long long ; 
    pair<ll,ll> dp[2][2][10][3][20] ; 
    ll solve(ll num){
        string s = to_string(num) ; 
        int m = s.size() ; 
        memset(dp,-1,sizeof(dp)) ;
        auto f = [&](auto&& f , bool tight , bool start , int digit , int inc , int idx) -> pair<ll, ll> {
            if(idx == m){
                return {1, 0} ; 
            }
            if(dp[tight][start][digit][inc][idx] != make_pair(-1,-1)){
                return dp[tight][start][digit][inc][idx] ;
            }
            int bound = (tight) ? s[idx] - '0' : 9 ; 
            ll ways = 0 ; 
            ll count = 0 ; 
            
            for(int i=0 ; i<=bound ; i++){
                bool next_tight = (tight) & (i == (s[idx] - '0'));
                pair<ll, ll> res;
                int added = 0; 
                if(!start){
                    if(i == 0) res = f(f, next_tight, 0 , i , 0 , idx+1) ; 
                    else res = f(f, next_tight, 1 , i , 0 , idx+1) ;
                }
                else if(i == digit){
                    res = f(f, next_tight , start , i , 0 , idx+1) ; 
                }
                else if(inc == 1){ // increasing
                    if(i < digit) { 
                        res = f(f, next_tight , start , i , 2 , idx+1 ) ; 
                        added = 1; 
                    }
                    else res = f(f, next_tight , start , i , 1 , idx+1) ; 
                }
                else if(inc == 2){ // decreasing
                    if(i < digit) res = f(f, next_tight , start , i , 2 , idx+1 ) ; 
                    else { 
                        res = f(f, next_tight , start , i , 1 , idx+1) ; 
                        added = 1; 
                    }
                }
                else{// inc = 0 -> equal
                    if(i < digit) res = f(f, next_tight , start , i , 2 , idx+1 ) ; 
                    else res = f(f, next_tight , start , i , 1 , idx+1) ; 
                }

                count += res.first;
                ways += res.second + (added * res.first); 
            }
            return dp[tight][start][digit][inc][idx] = {count, ways} ; 
        };

        return f(f,1,0,0,0,0).second ; 
    }
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1-1) ; 
    }
};