class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> m ; 
        for(int ele : nums){
            m[ele]++ ; 
        }
        vector<int> ans ; 
        for(auto p : m){
            if(p.second>1){
                ans.push_back(p.first) ; 
            }
        }
        return ans ; 
    }
};