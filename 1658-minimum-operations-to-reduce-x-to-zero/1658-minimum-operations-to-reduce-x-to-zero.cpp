class Solution {
public:
    using ll = long long ; 
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size() ; 

        vector<ll> prefix(n,0) ; 
        prefix[0] = nums[0] ; 
        for(int i=1 ; i<n ; i++){
            prefix[i] = prefix[i-1] + nums[i] ; 
        }

        vector<ll> suffix(n,0) ; 
        suffix[n-1] = nums[n-1] ; 
        for(int i=n-2; i>=0 ; i--){
            suffix[i] = suffix[i+1] + nums[i] ; 
        }
        reverse(suffix.begin(),suffix.end()) ; 

        int ans = n+1 ; 
        for(int i=0 ; i<n ; i++){
            int take = prefix[i] ; 
            int rem = x - take ; 
            if(rem == 0){
                ans = min(ans,i+1) ; 
            }
            int no = lower_bound(suffix.begin(),suffix.end(),rem) - suffix.begin() ; 

            if(no < n && suffix[no] + prefix[i] == x){
                ans = min(ans,i + no + 2) ; 
            }
        }

        int no = lower_bound(suffix.begin(),suffix.end(),x) - suffix.begin() ; 
        if(no < n && suffix[no] == x){
            ans = min(ans,no+1) ;
        }
        
        if(ans == n+1) return -1 ; 
        return ans ; 
    }
};