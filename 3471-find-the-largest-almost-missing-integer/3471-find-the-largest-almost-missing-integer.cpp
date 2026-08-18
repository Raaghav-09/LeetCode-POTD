class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> m ; 
        int n = nums.size() ; 
        for(int i=0 ; i<n ; i++){
            m[nums[i]]++ ; 
        } 
        if(k==n){
            int mx = -1 ; 
            for(auto pair : m){
                mx = max(mx,pair.first) ; 
            }
            return mx ; 
        }
        if(k==1 && n>=3){
            int mx = -1 ; 
            for(auto pair : m){
                if(pair.second==1) mx = max(mx,pair.first) ; 
            }
            return mx ; 
        }
        // int mx = -1 ; 
        // for(auto p : m){
        //     vector<int> v = p.second ; 
        //     if(p.first>mx){
        //         int s = v.size() ; 
        //         bool flag = true ; 
        //         for(int i=1 ; i<s ; i++){
        //             if(v[i]-v[i-1]+1>k){
        //                 flag = false ; 
        //                 break ; 
        //             }
        //         }
        //         if(flag) mx = p.first ; 
        //     }
        // }
        // return mx ; 
        if(m[nums[0]]>1 && m[nums[n-1]]>1) return -1 ; 
        else if(m[nums[0]]>1) return nums[n-1] ; 
        else if(m[nums[n-1]]>1) return nums[0] ; 
        return max(nums[0],nums[n-1]) ; 
    }
};