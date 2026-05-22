class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 

        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}} ; 

        deque<pair<int,int>> dq ; 
        vector<vector<int>> dist(n,vector<int>(m,1e9)) ;

        dq.push_front({0,0}) ; 
        dist[0][0] = 0 ; 

        while(dq.size()){
            int x = dq.front().first , y = dq.front().second ; 
            dq.pop_front() ; 

            int dir = grid[x][y] - 1 ; 
            for(int i=0 ; i<4 ; i++){
                int nx = x + dirs[i].first , ny = y + dirs[i].second ; 
                if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue ; 
                int cost = 1 ; 
                if(i == dir) cost = 0 ; 
                if(dist[x][y] + cost < dist[nx][ny]){
                    if(cost == 0){
                        dq.push_front({nx,ny}) ; 
                    }
                    else{
                        dq.push_back({nx,ny}) ; 
                    }
                    dist[nx][ny] = dist[x][y] + cost ; 
                }
            }
        }

        return dist[n-1][m-1] ; 
    }
};