class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 

        vector<pair<int,int>> dirs = {{-1,0},{0,-1},{0,1},{1,0}} ; 

        deque<vector<int>> dq ; 
        dq.push_front({0,0,0}) ; 
        vector<vector<int>> removals(n,vector<int>(m,INT_MAX)) ; 
        removals[0][0] = 0 ; 
        while(dq.size()){
            auto v = dq.front() ; 
            int x = v[0] , y = v[1] , steps = v[2] ; 
            dq.pop_front() ; 
            for(auto& [dx,dy] : dirs){
                int nx = x + dx , ny = y + dy ; 
                if(nx >= 0 && nx < n && ny>=0 && ny<m){
                    if(grid[nx][ny] == 0){
                        if(removals[nx][ny] > steps){
                            dq.push_front({nx,ny,steps}) ; 
                            removals[nx][ny] = steps ; 
                        }
                    }
                    else{
                        if(removals[nx][ny] > steps+1){
                            dq.push_back({nx,ny,steps+1}) ; 
                            removals[nx][ny] = steps+1 ; 
                        }
                    }
                }
            }
        }

        return removals[n-1][m-1] ; 
    }
};