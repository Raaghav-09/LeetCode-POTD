class Solution {
public:
    int f(vector<vector<int>>& g , vector<vector<vector<int>>>& dp , int i , int j , int& mxCost , int curr){
        int m = g.size() , n = g[0].size() ;
        int costToAdd ;
        if(g[i][j]==0) costToAdd = 0 ; 
        else costToAdd = 1 ; 

        if(curr+costToAdd>mxCost) return INT_MIN ; 

        if(dp[i][j][curr]!=-1) return dp[i][j][curr] ; 
        
        if(i==m-1 && j==n-1){
            if(curr+costToAdd<=mxCost) return dp[i][j][curr] = g[i][j] ; 
            else return INT_MIN ;
        }

        if(g[i][j]==0){
            if(i==m-1){
                return dp[i][j][curr] = f(g,dp,i,j+1,mxCost,curr) ; 
            }
            else if(j==n-1){
                return dp[i][j][curr] = f(g,dp,i+1,j,mxCost,curr) ; 
            }
            else{
                return dp[i][j][curr] = max(f(g,dp,i+1,j,mxCost,curr),f(g,dp,i,j+1,mxCost,curr)) ; 
            }
        }
        else{
            if(i==m-1){
                return dp[i][j][curr] = g[i][j]+f(g,dp,i,j+1,mxCost,curr+1) ; 
            }
            else if(j==n-1){
                return dp[i][j][curr] = g[i][j]+f(g,dp,i+1,j,mxCost,curr+1) ; 
            }
            else{
                return dp[i][j][curr] = g[i][j]+max(f(g,dp,i+1,j,mxCost,curr+1),f(g,dp,i,j+1,mxCost,curr+1)) ; 
            }
        }
        
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size() ; 
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(m+n-1,-1))) ;
        int ans = f(grid,dp,0,0,k,0) ;
        if(ans<0) ans = -1 ; 
        return ans ; 
        
    }
};