class Solution {
public:
    int cal(int i , int j , int edge , vector<vector<int>>& grid , int n , int m ){

        if(edge == 1) return grid[i][j] ; 

        int ans = 0 ; 
        int cnt = edge-1 ; 
        for(int ni = i , lj = j , rj = j ; cnt-- ; ni++ , lj-- , rj++){
            if(lj != rj){
                ans += grid[ni][lj] + grid[ni][rj] ; 
            }
            else{
                ans += grid[ni][lj] ; 
            }
        }

        cnt = edge ; 
        for(int ni = i+(2*edge-2) , lj = j , rj = j ; cnt-- ; ni-- , lj-- , rj++){
            if(lj != rj){
                ans += grid[ni][lj] + grid[ni][rj] ; 
            }
            else{
                ans += grid[ni][lj] ; 
            }
        }
        return ans ; 
    }

    void f(int i , int j , vector<vector<int>>& grid , int n , int m , set<int>& s){

        int down = n - i - ((n-i)%2 == 0 ? 1 : 0) ; 
        int dEdge = (down + 1) / 2 ; 
        int rEdge = j + 1 ; 
        int lEdge = m - j ; 
        
        int edge = min(dEdge , min(rEdge , lEdge)) ; 

        for(int len = 1 ; len <= edge ; len++){
            int ans = cal(i,j,len,grid,n,m) ; 
            s.insert(ans) ; 

            if(s.size() > 3) s.erase(s.begin()) ; 
        }
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 

        set<int> s ; 


        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                f(i , j , grid , n , m , s) ; 
            }
        }

        vector<int> ans(s.begin() , s.end()) ; 

        reverse(ans.begin() , ans.end()) ; 

        return ans ;
    }
};