class Solution {
public:
    int computeValue(vector<vector<int>>& grid , int row , int col , int k ){
        if(k==1) return 0 ; 
        int mn = grid[row][col] , mx = grid[row][col] ; 
        vector<int> v ; 
        for(int i=row ; i<row+k ; i++){
            for(int j=col ; j<col+k ; j++){
                v.push_back(grid[i][j]) ; 
            }
        }
        sort(v.begin(),v.end()) ; 
        int ans = INT_MAX ; 
        for(int i=1 ; i<v.size() ; i++){
            if(v[i]==v[i-1]) continue ; 
            ans = min(ans,v[i]-v[i-1]) ; 
        }
        if(ans==INT_MAX) ans = 0 ; 
        return ans ; 
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size() ; 
        int m = grid[0].size() ; 
        vector<vector<int>> ans(n-k+1,vector<int>(m-k+1)) ; 
        for(int startPosition_row=0 ; startPosition_row<=n-k ; startPosition_row++){
            for(int startPosition_col = 0 ; startPosition_col<=m-k ; startPosition_col++){
                ans[startPosition_row][startPosition_col] = computeValue(grid,startPosition_row,startPosition_col,k) ; 
            }
        }
        return ans ;
    }
};