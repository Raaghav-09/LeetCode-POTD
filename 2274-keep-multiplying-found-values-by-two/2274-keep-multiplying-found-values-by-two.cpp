class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s ; 
        int n =  nums.size() ;
        for(int i=0 ; i<n ; i++) s.insert(nums[i]) ; 
        bool found = true ; 
        while(found){
            if(s.find(original)!=s.end()){
                original=2*original ; 
            }
            else found = false ; 
        }
        return original ; 
    }
};