class NumMatrix {
private: 
    vector<vector<int>> dp ; 
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() ; 
        dp.assign(n,vector<int>(m,0)) ; 
        dp[0][0] = matrix[0][0] ; 

        for(int j=1 ; j<m ; j++){
            dp[0][j] = dp[0][j-1] + matrix[0][j] ;
        }
        for(int i=1 ; i<n ; i++){
            dp[i][0] = dp[i-1][0] + matrix[i][0] ; 
        }

        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<m ; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1] + matrix[i][j] - dp[i-1][j-1] ; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum1 = dp[row2][col2] , sum2 = 0 , sum3 = 0 , sum4 = 0 ;
        if(row1!=0 && col1!=0) sum2 = dp[row1-1][col1-1] ; 
        if(col1!=0) sum3 = dp[row2][col1-1] ; 
        if(row1!=0) sum4 = dp[row1-1][col2] ;
        int ans = sum1 + sum2 - sum3 - sum4 ; 
        return ans;  
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */