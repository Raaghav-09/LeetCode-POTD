class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long n = grid.size() ; 
        long long m = grid[0].size() ;
        vector<long long> hori(n) ; 
        for(long long i=0 ; i<n ; i++){
            long long sum = 0 ; 
            for(long long j=0 ; j<m ; j++){
                sum+=grid[i][j] ; 
            }
            hori[i] = sum ;  
        }
        vector<long long> ver(m) ; 
        for(long long j=0 ; j<m ; j++){
            long long sum = 0 ; 
            for(long long i=0 ; i<n ; i++){
                sum += grid[i][j] ; 
            }
            ver[j] = sum ;  
        }
        long long h = accumulate(hori.begin(),hori.end(),0LL) ; 
        long long v = accumulate(ver.begin(),ver.end(),0LL) ; 
        
        if(h%2==1 && v%2==1) return false ; 
        else if(h%2==1){
            long long req = v/2 ; 
            long long sum = 0 ; 
            for(long long i=0 ; i<m ; i++){
                sum+=ver[i] ; 
                if(sum==req) return true ; 
                else if(sum>req) return false ; 
            }
        }
        else if(v%2==1){
            long long req = h/2 ; 
            long long sum = 0 ; 
            for(long long i=0 ; i<n ; i++){
                sum+=hori[i] ; 
                if(sum==req) return true ; 
                else if(sum>req) return false; 
            }
        }
        else{
            long long req1 = v/2 ; 
            long long sum = 0 ; 
            bool flag = true ; 
            for(long long i=0 ; i<m ; i++){
                sum+=ver[i] ; 
                if(sum==req1){
                    flag = true ; 
                    break ; 
                }
                else if(sum>req1){
                    flag = false ; 
                    break ; 
                }
            }
            long long req2 = h/2 ; 
            sum = 0 ; 
            bool flag2 = true; 
            for(long long i=0 ; i<n ; i++){
                sum+=hori[i] ; 
                if(sum==req2){
                    flag2 = true ; 
                    break ; 
                }
                else if(sum>req2){
                    flag2 = false ; 
                    break ; 
                }
            }
            return flag || flag2 ; 
        }
        return false ; 
    }
};