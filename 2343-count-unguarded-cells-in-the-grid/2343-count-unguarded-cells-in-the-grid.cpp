class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<pair<int,int>> dir = {{-1,0},{0,-1},{0,1},{1,0}} ; 
        vector<vector<int>> grid(m,vector<int>(n,0)) ; 
        for(auto v : walls){
            int x = v[0] , y = v[1] ; 
            grid[x][y] = 1 ; 
        }
        queue<pair<int,int>> q ; 
        for(auto v : guards){
            int x = v[0] , y = v[1] ; 
            grid[x][y] = 2 ; 
            q.push({x,y}) ;
        }

        while(q.size()){
            auto [x,y] = q.front() ; q.pop() ; 
            for(int i=0 ; i<4 ; i++){
                int fx = x , fy = y ; 
                auto [dx,dy] = dir[i] ; 
                while(true){
                    int nx = fx + dx , ny = fy + dy ; 
                    if(nx>=0 && nx<m && ny>=0 && ny<n && (grid[nx][ny]==0 || grid[nx][ny]==3)){
                        grid[nx][ny] = 3 ; 
                        fx = nx , fy = ny ; 
                    }
                    else{
                        break ; 
                    }
                }
            }
        }
        int ans = 0 ; 
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]==0) ans++ ; 
            }
        }
        return ans ; 

    }
};