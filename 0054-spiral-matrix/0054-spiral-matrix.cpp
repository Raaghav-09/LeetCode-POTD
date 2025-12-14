class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() ; 
        int stc = 0 , enc = m-1 , str = 0 , enr = n-1 ; 
        vector<int> ans ; 
        int tne = m*n ; 
        int count = 1 ; 
        while(stc<=enc && str<=enr && count<=tne){
            // right
            for(int i = stc ; i<=enc && count<=tne ; i++){
                ans.push_back(matrix[str][i]) ; 
                count++ ; 
            }
            // down
            for(int j = str+1 ; j<enr && count<=tne ; j++){
                ans.push_back(matrix[j][enc]) ; 
                count++ ; 
            }
            // left
            for(int i= enc ; i>str && count<=tne ; i--){
                ans.push_back(matrix[enr][i]) ; 
                count++ ; 
            }
            // up 
            for(int j=enr ; j>str && count<=tne ; j--){
                ans.push_back(matrix[j][str]) ; 
                count++ ; 
            }
            str++ , enr-- , stc ++ , enc-- ; 
        }
        return ans ; 
    }
};