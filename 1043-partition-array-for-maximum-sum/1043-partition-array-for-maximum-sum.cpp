class Solution {
public:
    int dp[505] ; 
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size() ;

        auto f = [&](auto&& f , int i) -> int{
            if(i == n) return 0 ; 

            if(dp[i] != -1) return dp[i] ; 
            int res = 0 ; 
            int mx = arr[i] ; 
            for(int idx = i ; idx<min(n,i+k) ; idx++){
                mx = max(mx,arr[idx]) ; 
                int val = mx*(idx-i+1) + f(f,idx+1) ; 

                res = max(res,val) ; 
            }

            return dp[i] = res ; 
        };

        memset(dp,-1,sizeof(dp)) ; 
        return f(f,0) ; 
    }
};