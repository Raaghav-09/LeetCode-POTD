class Solution {
public:
    bool isSafe(int x , int y , int n , int m){
        return x>=0 && y>=0 && x<n && y<m ; 
    }
    bool f(int x , int y , vector<vector<char>>& board , vector<vector<bool>>& visited , string& word , int ind){
        int n = board.size() , m = board[0].size() ; 
        int sz = word.size() ; 

        if(ind == sz) return true ; 

        vector<pair<int,int>> dirs = {{-1,0} , {0,-1} , {0,1} , {1,0}} ; 
        
        bool ans = false ; 
        for(auto [dx,dy] : dirs){
            int nx = x+dx , ny = y + dy ; 
            if(isSafe(nx,ny,n,m) && !visited[nx][ny] && board[nx][ny] == word[ind]){
                visited[nx][ny] = true ; 
                ans |= f(nx , ny , board , visited , word , ind+1) ; 
                if(ans) return true ; 
                visited[nx][ny] = false ; 
            }
        }

        return ans ; 
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() , m = board[0].size() ; 
        vector<pair<int,int>> v ; 
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(board[i][j] == word[0]){
                    visited[i][j] = true;
                    if(f(i,j,board , visited , word , 1)) return true ;
                    visited[i][j] = false;
                }
            }
        }
        return false ; 
    }
};