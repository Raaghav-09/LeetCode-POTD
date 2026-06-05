class Solution {
public:
    int dp[50] ; 
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp)) ; 
        auto f = [&](int step,auto&& f)-> int{
            if(step == 1) return 1 ; 
            if(step == 0) return 1 ; 
            if(dp[step] != -1) return dp[step] ; 
            return dp[step] = f(step-1,f) + f(step-2,f) ; 

        };
        return f(n,f) ; 
    }
};