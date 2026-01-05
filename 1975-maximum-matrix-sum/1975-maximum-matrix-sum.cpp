class Solution {
public:
    long long sum(vector<vector<int>>& matrix){
        long long sum = 0 ; 
        for(int i=0 ; i<matrix.size() ; i++){
            for(int j=0 ; j<matrix[0].size() ; j++){
                sum+=abs(matrix[i][j]) ; 
            }
        }
        return sum ; 
    }
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size() ; 
        int m = matrix[0].size() ; 
        int mn = INT_MAX ; 
        int count = 0 ; 
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(matrix[i][j]<0){
                    count++ ; 
                }
                mn = min(abs(matrix[i][j]),mn); 
            }
        }
        if(count%2==0) return sum(matrix) ; 
        else return (sum(matrix)-2*mn) ; 
    }
};