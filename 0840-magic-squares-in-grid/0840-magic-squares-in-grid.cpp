class Solution {
public:
    bool validGrid(vector<vector<int>>& grid , int i , int j){
        int ideal = grid[i][j] + grid[i][j+1] + grid[i][j+2] ; 
        set<int> s ; 
        // horizontal 
        for(int k=j ; k<j+3 ; k++){
            int sum = 0 ; 
            for(int k2 = i ; k2 < i+3 ; k2++){
                if(grid[k2][k] > 9 || grid[k2][k]==0) return false ; 
                s.insert(grid[k2][k]) ; 
                sum += grid[k2][k] ;  
            } 
            if(sum != ideal) return false ; 
            sum = 0 ; 
        }
        if(s.size()!=9) return false ; 

        // vertical
        for(int k2 = i ; k2<i+3 ; k2++){
            int sum = 0 ; 
            for(int k=j ; k<j+3 ; k++){
                sum += grid[k2][k] ; 
            }
            if(sum != ideal) return false ; 
            sum = 0 ; 
        }

        // diagonal1 : - 
        int sum = 0 ; 
        for(int k = 0 ; k<3 ; k++){
            sum += grid[i+k][j+k] ; 
        }
        if(sum!=ideal) return false ; 

        // diagonal2 :-
        sum = 0 ; 
        for(int k=0 ; k<3 ; k++){
            sum += grid[i+k][j+2-k] ; 
        }
        if(sum != ideal) return false ; 
        return true ; 
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 
        int ans = 0 ; 
        for(int i=0 ; i<n-2 ; i++){
            for(int j=0 ; j<m-2 ; j++){
                ans += validGrid(grid,i,j) ; 
            }
        }
        return ans ; 
    }
};