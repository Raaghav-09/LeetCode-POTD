class Solution {
public:
    int inf = 2e9  ; 
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ; 

        vector<vector<int>> time(m,vector<int>(n,-1)) ; 
        queue<vector<int>> q ; 
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 1){
                    q.push({i,j,0}) ; 
                    time[i][j] = 0 ; 
                }

            }
        }

        vector<pair<int,int>> dirs = {{-1,0},{0,-1},{0,1},{1,0}} ; 

        while(q.size()){
            int sz = q.size() ; 
            while(sz--){
                auto v = q.front() ; q.pop() ; 
                int x = v[0] , y = v[1] , t = v[2] ; 

                for(auto [dx,dy] : dirs){
                    int nx = x + dx , ny = y + dy ; 
                    if(nx < m && nx>=0 && ny<n && ny>=0 && time[nx][ny] == -1){
                        if(grid[nx][ny] == 0){
                            q.push({nx,ny,t+1}) ; 
                            time[nx][ny] = t+1 ; 
                        }
                    }
                }
            }
        }

        vector<vector<int>> vis(m,vector<int>(n,0)) ;
        auto check = [&](int mxTime)->bool{

            queue<vector<int>> path ; 
            path.push({0,0,mxTime}) ;  
            vis[0][0] = 1 ; 
            while(path.size()){
                auto v = path.front() ; path.pop() ; 
                int x = v[0] , y = v[1] , t = v[2] ; 
                if(x == m-1 && y == n-1) return true ; 
                for(auto [dx,dy] : dirs){
                    int nx = x + dx , ny = y + dy ; 
                    
                    if(nx<m && nx>=0 && ny<n && ny>=0 && vis[nx][ny] == 0 && grid[nx][ny] == 0){

                        int tame = (time[nx][ny] == -1) ? inf : time[nx][ny] ; 
                        if(t+1<tame || (nx == m-1 && ny == n-1 && t+1 <= tame)){
                            vis[nx][ny] = 1 ; 
                            path.push({nx,ny, t+1}) ;
                        }
                    }
                }
            }
            return false ; 
        };

        auto fill = [&]()->void{
            for(int i=0 ; i<m ; i++){
                for(int j=0 ; j<n ; j++){
                    vis[i][j] = 0 ; 
                }
            }
        };

        int low = 0 , high = 1e9 ; 
        int ans = -1 ; 
        while(low <= high){
            int mid = low + (high - low)/2 ; 
            fill() ; 
            if(check(mid)){
                ans = mid ; 
                low = mid + 1 ; 
            }
            else{
                high = mid-1 ; 
            }
        }

        return ans ; 
    }
};