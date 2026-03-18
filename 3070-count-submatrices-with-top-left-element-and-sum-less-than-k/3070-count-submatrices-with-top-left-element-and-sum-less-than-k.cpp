class Solution {
public:
    using ll = long long ; 
    long long query(int l , int r , vector<vector<long long>>& prefix){
        return prefix[l][r] ; 
    }
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size() ;

        vector<vector<ll>> prefix(n , vector<ll>(m,0)) ; 
        prefix[0][0] = grid[0][0] ; 

        for(int i=1 ; i<n ; i++) prefix[i][0] = prefix[i-1][0] + grid[i][0] ; 
        for(int j=1 ; j<m ; j++) prefix[0][j] = prefix[0][j-1] + grid[0][j] ; 

        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<m ; j++){
                prefix[i][j] = grid[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] ; 
            }
        }
        int ans = 0 ; 
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(prefix[i][j] <= k) ans++ ; 
            }
        }

        return ans ; 
    }
};