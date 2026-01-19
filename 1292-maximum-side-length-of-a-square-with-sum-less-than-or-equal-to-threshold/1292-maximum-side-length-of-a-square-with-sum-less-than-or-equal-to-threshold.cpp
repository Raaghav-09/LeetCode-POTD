class Solution {
public:
    long long getSum(vector<vector<long long>>& pre , int row , int col , int sideLength){
        int endRow = row + sideLength - 1 , endCol = col + sideLength - 1 ; 
        long long sum1 = 0 , sum2 = 0 , sum3 = 0 , sum4 = 0 ; 
        if(row == 0 && col == 0) return pre[endRow][endCol] ; 
        if(row!=0){
            sum1 = pre[row-1][endCol] ; 
        }
        if(col!=0){
            sum2 = pre[endRow][col-1] ; 
        }
        if(row!=0 && col!=0){
            sum3 = pre[row-1][col-1] ; 
        }
        sum4 = pre[endRow][endCol] ; 
        return sum4 + sum3 - sum2 - sum1 ; 
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size() , m = mat[0].size() ; 
        vector<vector<long long>> pre(n , vector<long long>(m , 0)) ; 
        pre[0][0] = mat[0][0] ; 
        for(int i=1 ; i<n ; i++){
            pre[i][0] = pre[i-1][0] + mat[i][0] ; 
        }
        for(int j=1 ; j<m ; j++){
            pre[0][j] = pre[0][j-1] + mat[0][j] ; 
        }
        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<m ; j++){
                pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + mat[i][j] ; 
            }
        }

        int ans = 0 ; 
        for(int sideLength = 1 ; sideLength<=min(n,m) ; sideLength++){
            for(int i=0 ; i<=n-sideLength ; i++){
                for(int j=0 ; j<=m-sideLength ; j++){
                    long long sum = getSum(pre , i , j , sideLength) ; 
                    if(sum<=threshold){
                        ans = max(ans , sideLength ) ;
                    }
                }
            }
        }

        return ans ; 

    }
};