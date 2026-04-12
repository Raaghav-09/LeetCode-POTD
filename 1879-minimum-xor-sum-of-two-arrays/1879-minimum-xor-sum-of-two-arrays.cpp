class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() ;
        vector<vector<int>> dp(n,vector<int>(1 << n , -1)) ; 
        auto f = [&](int ind , int mask , auto&& f) -> int{
            if(ind == n){
                return 0 ; 
            }
            if(dp[ind][mask] != -1) return dp[ind][mask] ; 
            int ans = INT_MAX ; 
            for(int i=0 ; i<n ; i++){
                if((mask & 1 << i) == 0){
                    int res = (nums1[ind] ^ nums2[i]) + f(ind+1,mask | 1 << i , f) ; 
                    ans = min(ans,res) ; 
                }
            }

            return dp[ind][mask] = ans ; 
        };

        return f(0,0,f) ; 
    }
};