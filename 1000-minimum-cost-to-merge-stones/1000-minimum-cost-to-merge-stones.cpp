class Solution {
public:
    int dp[31][31] ; 
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size() ; 
        if((n-1) % (k-1) != 0) return -1 ; 

        vector<int> pre(n+1,0) ; 
        for(int i=0 ; i<n ; i++) pre[i+1] = pre[i] + stones[i] ; 

        auto f = [&](auto&& f , int l , int r) -> int{
            if(l == r) return 0 ;
        
            int res = 1e9 ; 
            if(dp[l][r] != -1) return dp[l][r] ; 
            for(int i=l ; i<r ; i+=(k-1)){
                int cost = f(f,l,i) + f(f,i+1,r) ; 
                res = min(res , cost ) ; 
            }

            if((r-l) % (k-1) == 0){
                res = res + pre[r+1] - pre[l] ; 
            }

            return dp[l][r] = res ; 
        };

        memset(dp,-1,sizeof(dp)) ; 
        return f(f,0,n-1) ; 
    }
};