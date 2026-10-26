class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size() ; 
        int m = grid[0].size() ;
        int cnt = 0 ; 
        queue<pair<int,int>> q ; 
        q.push({0,0}) ; 
        vector<vector<int>> vis(n,vector<int>(m,0)) ; 
        vector<pair<int,int>> dir = {{-1,0},{0,-1},{1,0},{0,1}} ; 

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(vis[i][j]==1) continue ; 
                if(grid[i][j]==0){
                    vis[i][j] = 1 ; 
                    continue ; 
                }
                queue<pair<int,int>> q ; 
                q.push({i,j}) ; 
                long long val = 0 ; 
                vis[i][j] = 1 ; 
                while(q.size()){
                    auto [x,y] = q.front() ; 
                    q.pop() ; 
                    val += grid[x][y] ; 
                    for(int l=0 ; l<4 ; l++){
                        int nx = x+dir[l].first , ny = y+dir[l].second ; 
                        if(nx>=0 && ny>=0 && nx<n && ny<m && vis[nx][ny]==0 && grid[nx][ny]!=0){
                            q.push({nx,ny}) ; 
                            vis[nx][ny] = 1 ; 
                        }
                    }
                }
                if(val%k==0) cnt++ ; 
            }
        }
        return cnt ; 
        
    }
};