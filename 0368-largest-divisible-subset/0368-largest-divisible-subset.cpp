class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size() ; 
        sort(nums.begin(),nums.end()) ; 
        vector<int> dp(n,1) ; 
        vector<int> ind(n) ; 
        int ansInd = 0 ; 
        iota(ind.begin(),ind.end(),0) ; 
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if((nums[i] % nums[j]) == 0){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1 ; 
                        ind[i] = j ; 
                    }
                }
            }
            if(dp[i] > dp[ansInd]){
                ansInd = i ; 
            }
        }

        vector<int> ans ; 
        while(ind[ansInd] != ansInd){
            ans.push_back(nums[ansInd]) ;
            ansInd = ind[ansInd] ; 
        }
        ans.push_back(nums[ansInd]) ; 
        reverse(ans.begin(),ans.end()) ; 

        return ans ; 
    }
};