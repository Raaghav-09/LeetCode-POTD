class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() ; 
        
        sort(costs.begin(),costs.end(),[&](vector<int>& v1 , vector<int>& v2){
            return v1[0] - v1[1] < v2[0] - v2[1] ; 
        }) ; 

        int ans = 0 ; 
        for(int i=0 ; i<n/2 ; i++){
            ans += costs[i][0] ; 
        }
        for(int i=n/2 ; i<n ; i++){
            ans += costs[i][1] ; 
        }

        return ans ; 
    }
};