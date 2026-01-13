class Solution {
public: 
// DO THIS Question again -> Very Important
    // TLE dega -> nhi diya -> But think better
    // bool check(vector<vector<long long>>& dp , int row1 , int col1 , int row2 , int col2 , int target){
    //     int sum1 = dp[row2][col2] , sum2 = 0 , sum3 = 0 , sum4 = 0 ;
    //     if(row1!=0 && col1!=0) sum2 = dp[row1-1][col1-1] ; 
    //     if(col1!=0) sum3 = dp[row2][col1-1] ; 
    //     if(row1!=0) sum4 = dp[row1-1][col2] ;
    //     long long ans = sum1 + sum2 - sum3 - sum4 ; 
    //     return ans == target ; 
    // }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // int n = matrix.size() , m = matrix[0].size() ; 

        // // Constructing dp or prefix sum

        // vector<vector<long long>> dp(n,vector<long long>(m,0)) ; 
        // dp[0][0] = matrix[0][0] ; 
        // for(int i=1 ; i<n ; i++){
        //     dp[i][0] = matrix[i][0] + dp[i-1][0] ; 
        // }
        // for(int j=1 ; j<m ; j++){
        //     dp[0][j] = dp[0][j-1] + matrix[0][j] ; 
        // }

        // for(int i=1 ; i<n ; i++){
        //     for(int j=1 ; j<m ; j++){
        //         dp[i][j] = dp[i-1][j] + dp[i][j-1] + matrix[i][j] - dp[i-1][j-1] ; 
        //     }
        // }

        // Consider all possible ways to form subMatrix => TLE becoz 10000C2 
        // m*n + (m-1)*(n-1) + (m-2)*(n-2) ......... + 
        // int ans = 0 ; 
        // for(int i=0 ; i<n ; i++){
        //     for(int j=0 ; j<m ; j++){
        //         for(int ii=i ; ii<n ; ii++){
        //             for(int jj=j ; jj<m ; jj++){
        //                 ans += check(dp , i , j , ii , jj ,target) ; 
        //             }
        //         }
        //     }
        // }
        // return ans ; 

        int n = matrix.size() , m = matrix[0].size() ; 
        // Do it again
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        for (int i = 0; i < n; i++ ) {
            dp[i][0] = matrix[i][0];
            for (int j=1 ; j<m ; j++) dp[i][j] = dp[i][j-1] + matrix[i][j];
        }

        int ans = 0 ; 

        for(int left = 0 ; left<m ; left++){
            for(int right=left ; right<m ; right++){

                map<int,int> mp ; 
                mp[0] = 1 ; 
                long long curr = 0 ; 

                for(int row=0 ; row<n ; row++){

                    long long val = dp[row][right] ; 
                    if(left!=0) val -= dp[row][left-1] ; 
                    curr += val ; 
                    
                    if(mp.find(curr - target) != mp.end()) ans += mp[curr - target] ; 
                    mp[curr]++ ; 

                }

            }
        }
        return ans ; 

    }
};