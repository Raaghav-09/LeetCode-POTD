class Solution {
public:
    int helper(vector<int>& piles , int l , int r , vector<vector<int>>& dp){
        if(l==r) return piles[l] ; 
        if(dp[l][r]!=-1) return dp[l][r] ; 
        int left = piles[l] + helper(piles,l+1,r,dp) ; 
        int right = piles[r] + helper(piles,l,r-1,dp) ;
        return dp[l][r] = max(left,right) ; 
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size() ; 
        vector<vector<int>> dp(n,vector<int>(n,-1)) ; 
        int mx = helper(piles,0,n-1,dp) ; 
        int sum = accumulate(piles.begin(),piles.end(),0LL) ; 
        int remain = sum - mx ; 
        return mx > remain ; 
    }
};