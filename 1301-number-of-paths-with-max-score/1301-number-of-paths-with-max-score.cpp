class Solution {
public:
    const int inf = 1e5 ; 
    const int mod = 1e9 + 7 ; 
    vector<int> pathsWithMaxScore(vector<string>& grid) {
        int n = grid.size() ; 

        // queue<pair<int,int>> q ; 
        // q.push(make_pair(n-1,n-1)) ; 
        
        vector<pair<int,int>> dirs = {{1,0},{0,1},{1,1}} ; 

        // while(!q.empty()){
        //     auto [x,y] = q.front() ; q.pop() ; 

        //     for(auto& [dx,dy] : dirs){
        //         int nx = x + dx , ny = y + dy ; 
        //         if(nx>=0 && n){

        //         }
        //     }

        // }
        grid[0][0] = '0' ; 
        grid[n-1][n-1] = '0' ; 
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,make_pair(0,1))) ; 
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=n-1 ; j>=0 ; j--){
                if(grid[i][j] == 'X'){
                    dp[i][j] = make_pair(-inf,0) ; 
                    continue ; 
                }
                int mx = -inf ; 
                for(auto& [dx,dy] : dirs){
                    int ni = i+dx , nj = j+dy ; 
                    if(ni<n && nj<n){
                        if(grid[ni][nj] == 'X') continue ; 
                        mx = max(mx,dp[ni][nj].first) ; 
                    }
                }
                if(mx < 0){
                    dp[i][j] = {-inf,0} ; 
                }
                else{
                    long long ways = 0 ; 
                    for(auto& [dx,dy] : dirs){
                        int ni = i+dx , nj = j+dy ; 
                        if(ni<n && nj<n){
                            if(grid[ni][nj] == 'X') continue ; 
                            if(dp[ni][nj].first == mx){
                                ways += dp[ni][nj].second ; 
                                ways %= mod ; 
                            }
                        }
                    }
                    dp[i][j] = make_pair(mx+grid[i][j]-'0',ways) ; 
                }
                if(i == n-1 && j == n-1) dp[i][j] = make_pair(0,1) ; 
            }
        }
        if(dp[0][0].second == 0) return {0,0} ;  
        return  {dp[0][0].first , dp[0][0].second } ; 
    }
};