class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int limit = 1e5 + 1 ; 
        int n = nums.size() ; 
        vector<vector<int>> v(limit) ; 
        vector<bool> consider(limit , true) ; 
        for(int i=2 ; i<limit ; i++){
            for(int j=i ; j<limit ; j+=i){
                if(v[j].size()<3){
                    v[j].push_back(i) ;
                }
                else consider[j] = false; 
            }
        }
        int ans = 0 ; 
        for(int i=0 ; i<n ; i++){
            if(consider[nums[i]] && v[nums[i]].size()==3){
                for(int ele : v[nums[i]]){
                    ans += ele ; 
                }
                ans += 1 ; 
            }
        }

        return ans ; 
    }
};