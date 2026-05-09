class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size() ; 

        int sr = 0 , sc = 0 , er = n-1 , ec = m-1 ; 

        while(sr <= er && sc <= ec){

            vector<int> temp ; 
            for(int i=sc ; i<ec ; i++){
                temp.push_back(grid[sr][i]) ; 
            }

            for(int i=sr ; i<er ; i++){
                temp.push_back(grid[i][ec]) ; 
            }

            for(int i=ec ; i>sc ; i--){
                temp.push_back(grid[er][i]) ; 
            }

            for(int i=er ; i>sr ; i--){
                temp.push_back(grid[i][sc]) ; 
            }

            int total = temp.size() ;
            int ktemp = k%total ;  

            // 1 2 3 4 5 6 after k rotation to left
            // 2 3 4 5 6 1 -> 1st
            // 3 4 5 6 1 2 -> 2nd
            // 4 5 6 1 2 3 -> 3rd

            reverse(temp.begin(),temp.begin()+ktemp) ; 
            reverse(temp.begin()+ktemp,temp.end()) ; 
            reverse(temp.begin(),temp.end()) ; 

            int index = 0 ; 

            for(int i=sc ; i<ec ; i++){
                grid[sr][i] = temp[index++] ; 
            }

            for(int i=sr ; i<er ; i++){
                grid[i][ec] = temp[index++] ; 
            }

            for(int i=ec ; i>sc ; i--){
                grid[er][i] = temp[index++] ; 
            }

            for(int i=er ; i>sr ; i--){
                grid[i][sc] = temp[index++] ; 
            }
            sc++ , ec-- ; 
            sr++ , er-- ; 
        }

        return grid ; 

    }
};