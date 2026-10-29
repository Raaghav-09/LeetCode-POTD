class Solution {
public:
    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 

        /*
        1  2 
        3  4 

        xor minimize 

        a xor c = x1
        b xor c = x2

        a < b 
        1001 111 = 14
        1010 111 = 13 
        x1 > x2 

        => instead think in terms of bit 
        what if i make 10 different grid each having the bit 

        001  010
        011  100

        */
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(1024,0))) ; 

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(i == 0 && j== 0){
                    dp[i][j][grid[i][j]] = 1 ; 
                }
                if(j>0){
                    for(int k=0 ; k<1024 ; k++){
                        if(dp[i][j-1][k] == 1){
                            dp[i][j][k^grid[i][j]] = 1 ; 
                        }
                    }
                }
                if(i > 0){
                    for(int k=0 ; k<1024 ; k++){
                        if(dp[i-1][j][k] == 1){
                            dp[i][j][k^grid[i][j]] = 1 ; 
                        }
                    }
                }
            }
        }

        int ans = 1024 ; 
        for(int k=0 ; k<1024 ; k++){
            if(dp[n-1][m-1][k] == 1) return k ; 
        }
        return ans ; 
    }
};