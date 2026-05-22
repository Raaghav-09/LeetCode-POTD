class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 
        vector<vector<int>> dist(n,vector<int>(m,1e9)) ; 
        deque<pair<int,int>> dq ; 

        dq.push_front({0,0}) ; 
        dist[0][0] = 0 ; 

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while(dq.size()){
            int x = dq.front().first , y = dq.front().second ; dq.pop_front() ; 

            for(auto [dx,dy] : dirs){
                int nx = x + dx , ny = y + dy ; 
                if(nx >=0 && nx<n && ny>=0 && ny<m){
                    if(dist[x][y] + grid[nx][ny] < dist[nx][ny]){
                        dist[nx][ny] = dist[x][y] + grid[nx][ny] ; 

                        if(grid[nx][ny] == 0){
                            dq.push_front({nx,ny}) ; 
                        }
                        else{
                            dq.push_back({nx,ny}) ;
                        }
                    }
                }
            }

        }

        return dist[n-1][m-1] ; 
    }
};