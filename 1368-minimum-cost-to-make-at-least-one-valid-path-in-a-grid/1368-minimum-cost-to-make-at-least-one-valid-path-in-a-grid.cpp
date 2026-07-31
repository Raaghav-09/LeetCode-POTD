class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 

        vector<vector<int>> visited(n,vector<int>(m,INT_MAX)) ; 

        vector<pair<int,int>> dirs = {{0,0},{0,1},{0,-1},{1,0},{-1,0}} ; 

        deque<vector<int>> dq ; 
        dq.push_front({0,0,0}) ; 
        visited[0][0] = 1 ; 

        while(dq.size()){
            auto v = dq.front() ; dq.pop_front() ; 
            int cost = v[0] , x = v[1] , y = v[2] ; 

            if(x == n-1 && y == m-1) return cost ; 
            for(int i=1 ; i<5 ; i++){
                int nx = x + dirs[i].first , ny = y + dirs[i].second ;
                if(nx>=0 && nx<n && ny>=0 && ny<m ){
                    int c = (grid[x][y] != i) ; 
                    
                    if(visited[nx][ny] > cost+c){
                        if(c == 1){
                            dq.push_back({cost+c,nx,ny}) ; 
                            visited[nx][ny] = cost + c ; 
                        }
                        else{
                            dq.push_front({cost,nx,ny}) ; 
                            visited[nx][ny] = cost ; 
                        }
                    }
                }
            }
        }

        return -1 ; 
    }
};