class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> decYet(n) ; 
        decYet[0] = nums[0] ;
        int mx = nums[0] ; 
        for(int i=1 ; i<n ; i++){
            mx = max(mx,nums[i]) ; 
            decYet[i] = mx ; 
        }
        vector<int> suffixmn(n,0) ; // because traveling n-1 to 0 and knowing that what is the minimum ele till that points
        int mn = nums.back() ; 
        for(int i=n-1 ; i>=0 ; i--){
            mn = min(mn,nums[i]) ; 
            suffixmn[i] = mn ; 
        }
        
        int j = 0 ; 
        vector<int> ans(n) ; 
        for(int i=0 ; i<n ; i++){
            if(i==n-1 || decYet[i]<=suffixmn[i+1]){
                while(j<=i){
                    ans[j] = decYet[i] ; 
                    j++ ; 
                }
            }
        }
        return ans ; 
    }
};