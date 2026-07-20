class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size() ; 

        vector<pair<int,int>> dirs = {{-1,0},{0,-1},{0,1},{1,0}} ; 
        /*
        {steps , removals , x , y}
        */

        queue<vector<int>> pq ; 
        pq.push({0,0,0,0}) ; 
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,INT_MAX))) ; 
        for(int i=0 ; i<=k ; i++) dp[0][0][0] = 0 ; 
        while(pq.size()){
            auto v = pq.front() ; pq.pop() ; 

            int steps = v[0] , removals = v[1] , x = v[2] , y = v[3] ; 
            for(auto& [dx,dy] : dirs){
                int nx = x + dx , ny = y + dy ; 
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    if(grid[nx][ny] == 1){
                        if(removals + 1 <=k && dp[nx][ny][removals+1] > steps+1){
                            pq.push({steps+1,removals+1,nx,ny}) ; 
                            dp[nx][ny][removals+1] = steps+1 ; 
                        }
                    }
                    else{
                        if(dp[nx][ny][removals] > steps+1){
                            pq.push({steps+1,removals,nx,ny}) ; 
                            dp[nx][ny][removals] = steps+1 ; 
                        }
                    }
                }
            }
        }

        int ans = INT_MAX ; 
        for(int i=0; i<=k ; i++){
            ans = min(ans,dp[n-1][m-1][i]) ; 
        }

        if(ans == INT_MAX) return -1 ; 
        return ans ; 
    }
};