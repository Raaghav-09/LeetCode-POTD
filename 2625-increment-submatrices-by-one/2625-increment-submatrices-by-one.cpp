class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n,vector<int>(n,0)) ; 
        int m = queries.size() ; 
        for(int i=0 ; i<m ; i++){
            int l1 = queries[i][0] , r1 = queries[i][1] ; 
            int l2 = queries[i][2] , r2 = queries[i][3] ; 
            for(int row=l1 ; row<=l2 ; row++){
                ans[row][r1] += 1 ; 
                if(r2+1<n) ans[row][r2+1] += -1 ; 
            }
        }

        for(int i=0 ; i<n ; i++){
            for(int j=1 ; j<n ; j++){
                ans[i][j] += ans[i][j-1] ; 
            }
        }
        
        return ans ; 

    }
};