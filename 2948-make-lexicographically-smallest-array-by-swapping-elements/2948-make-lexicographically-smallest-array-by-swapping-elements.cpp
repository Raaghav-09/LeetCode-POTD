class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size() ; 

        vector<int> dummy = nums ; 
        sort(dummy.begin(),dummy.end()) ; 

        map<int,queue<int>> mp ; 
        for(int i=0; i<n ; i++){
            mp[nums[i]].push(i) ; 
        }

        vector<vector<int>> belongs ;
        vector<vector<int>> belongs_values ;  
        int i=0 ; 
        while(i<n){
            int prev = dummy[i] ; 
            vector<int> temp_values ; 
            vector<int> temp ; 
            while(i<n && (dummy[i]-prev) <= limit){
                temp_values.push_back(dummy[i]) ; 

                temp.push_back(mp[dummy[i]].front()) ; 
                mp[dummy[i]].pop() ; 

                prev = dummy[i] ; 
                i++ ; 
            }
            belongs.push_back(temp) ;
            belongs_values.push_back(temp_values) ; 
        }

        for(auto& v : belongs){
            sort(v.begin(),v.end()) ; 
        }

        vector<int> ans(n) ; 
        int m = belongs.size() ; 
        for(int i=0 ; i<m ; i++){
            int sz = belongs[i].size() ; 
            for(int j=0 ; j<sz ; j++){
                ans[belongs[i][j]] = belongs_values[i][j] ; 
            }
        }

        return ans ; 
    }
};