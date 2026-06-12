class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& bl) {
        int n = bl.size() ; 
        multiset<int> mul ; 
        // vector<vector<int>> remove(n,vector<int>(2)) ; // at which point , what to remove
        // for(int i=0 ; i<n ; i++){
        //     v[i][0] = bl[i][1] ; 
        //     v[i][1] = bl[i][2] ; 
        // }

        // sort(remove.begin(),remove.end()) ; 
        map<int,vector<int>> check ; // x coordinate , what height to remove or add
        for(int i=0 ; i<n ; i++){
            check[bl[i][0]].push_back(bl[i][2]) ; 
            check[bl[i][1]].push_back(-1*bl[i][2]) ; 
        } 

        mul.insert(0) ; 
        vector<vector<int>> ans ; 
        for(auto [x,v] : check){
            int prev = *mul.rbegin() ; 

            for(auto ele : v){
                if(ele < 0){
                    ele *= -1 ; 
                    mul.erase(mul.find(ele)) ; 
                }
                else{
                    mul.insert(ele) ; 
                }
            }

            int curr = *mul.rbegin() ; 

            if(curr != prev) ans.push_back({x,curr}) ; 
        }

        return ans ; 
    }
};