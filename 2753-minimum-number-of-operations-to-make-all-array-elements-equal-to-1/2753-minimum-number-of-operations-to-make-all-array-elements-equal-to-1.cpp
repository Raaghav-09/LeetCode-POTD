class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size() ; 
        int minDis = n+1 ; 
        pair<int,int> req ;
        for(int i=0 ; i<n ; i++){
            int gcd = nums[i] ; 
            if(nums[i]==1){
                minDis = 0 ; 
                req.first = i ; 
                break ; 
            }
            for(int j=i+1 ; j<n ; j++){
                gcd = __gcd(gcd,nums[j]) ; 
                if(gcd==1){
                    if(j-i<minDis){
                        minDis = j-i ; 
                        req.first = i ; 
                        req.second = j ; 
                        break ; 
                    }
                }
            }
        }
        if(minDis==n+1) return -1 ; 
        int f = req.first ; 
        int ans = minDis ; 
        int t = f ; 
        f-- ; 
        while(f>=0){
            if(nums[f]==1){
                f-- ; 
                continue ; 
            }
            else{
                ans++ ; 
                f-- ; 
            }
        }
        f = t+1 ; 
        while(f<n){
            if(nums[f]==1){
                f++ ; 
                continue ; 
            }
            else{
                ans++ ; 
                f++ ; 
            }
        }
        return ans ; 
    }
};