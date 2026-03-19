class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 

        vector<vector<pair<int,int>>> prefix(n , vector<pair<int,int>>(m)) ; 
        prefix[0][0] = make_pair(((grid[0][0] == 'X') ? 1 : 0) , ((grid[0][0] == 'Y') ? 1 : 0)) ; 

        for(int i=1 ; i<n ; i++){
            int dx = (grid[i][0] == 'X') , dy = (grid[i][0] == 'Y') ; 
            prefix[i][0] = make_pair(prefix[i-1][0].first + dx , prefix[i-1][0].second + dy) ;
        }
        for(int j=1 ; j<m ; j++){
            int dx = (grid[0][j] == 'X') , dy = (grid[0][j] == 'Y') ; 
            prefix[0][j] = make_pair(prefix[0][j-1].first + dx , prefix[0][j-1].second + dy) ; 
        }

        for(int i=1 ; i<n ; i++){
            for(int j=1 ; j<m ; j++){
                int lx = prefix[i-1][j].first , ly = prefix[i-1][j].second ; 
                int rx = prefix[i][j-1].first , ry = prefix[i][j-1].second ; 
                int dx = prefix[i-1][j-1].first , dy = prefix[i-1][j-1].second ; 
                int x = (grid[i][j] == 'X') , y = (grid[i][j] == 'Y') ; 
                prefix[i][j] = make_pair(x + lx + rx - dx , y + ly + ry - dy) ; 
            }
        }

        int ans = 0 ; 
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                int x = prefix[i][j].first , y = prefix[i][j].second ; 
                if(x > 0 && x == y) ans++ ; 
            }
        }

        return ans ; 
    }
};