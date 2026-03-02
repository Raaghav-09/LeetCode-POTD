class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size() ; 

        vector<long long> prefix(n,0) ; 

        prefix[0] = nums[0] ; 
        for(int i=1 ; i<n ; i++){
            prefix[i] = prefix[i-1] + nums[i] ; 
        }

        set<pair<long long,int>> ss ; 
        ss.insert({0,-1}) ; 
        int j = 0 ; 
        int ans = n+1 ; 
        while(j<n){
            while(j<n && ss.size() && (prefix[j] - ss.begin()->first) >= k){
                ans = min(ans,j - ss.begin()->second ) ; 
                ss.erase(*ss.begin()) ; 
            }
            ss.insert({prefix[j] , j}) ; 
            j++; 
        }
        if(ans == n+1) return -1 ; 
        return ans ; 
    }
};