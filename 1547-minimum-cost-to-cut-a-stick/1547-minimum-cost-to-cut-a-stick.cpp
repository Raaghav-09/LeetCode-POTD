class Solution {
public:
    int dp[105][105] ; 
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size() ; 

        /*
        dp[i][j] = minimum cost to cut this part of the stick 
        */
        cuts.push_back(0) ; 
        cuts.push_back(n) ;
        memset(dp,-1,sizeof(dp)) ; 
        sort(cuts.begin(),cuts.end()) ; 
        auto f = [&](auto&& f , int l , int r )-> int{
            
            if(l > r) return 0 ;
            if(dp[l][r] != -1) return dp[l][r] ;
            int res = 1e9 ; 
            int len = cuts[r+1]-cuts[l-1] ; 
            for(int i=l ; i<=r ; i++){
                res = min(res , len + f(f,l,i-1) + f(f,i+1,r)) ; 
            }
            return dp[l][r] = res ; 
        };

        return f(f,1,m) ; 
    }
};