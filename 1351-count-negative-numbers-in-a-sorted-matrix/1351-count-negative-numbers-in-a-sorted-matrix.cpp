class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ; 
        int ans = 0 ; 
        for(int i=0 ; i<n ; i++){
            int low = 0 , high = m-1 ; 
            int ind = -1 ; 
            while(low<=high){
                int mid = (low+high)/2 ; 
                if(grid[i][mid]<0){
                    ind = mid ; 
                    high = mid - 1 ; 
                }
                else{ // grid[i][mid] >=0 
                    low = mid + 1 ; 
                }
            }
            if(ind!=-1) ans += (m - ind) ; 
        }
        return ans ; 
    }
};