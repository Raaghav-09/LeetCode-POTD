class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 
        vector<vector<int>> visited(n,vector<int>(m,0)) ;

        vector<pair<int,int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}} ; 

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq ; 
        pq.push({grid[0][0],0,0}) ; 
        visited[0][0] = 1 ; 

        while(pq.size()){
            auto v = pq.top() ; pq.pop() ; 
            int t = v[0] , x = v[1] , y = v[2] ; 

            if(x == n-1 && y == m-1) return t ; 

            for(auto [dx,dy] : dirs){
                int nx = x + dx , ny = y + dy ; 
                if(nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny] == 0){
                    visited[nx][ny] = max(t,grid[nx][ny]) ; 
                    pq.push({max(t,grid[nx][ny]),nx,ny}) ; 
                }
            }
        }

        return -1 ; 
    }
};