class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size() ; 
        sort(nums1.begin(),nums1.end()) ; 

        vector<int> pre(n) ; 
        pre[0] = nums1[0] %2 ; 
        for(int i=1 ; i<n ; i++){
            pre[i] = pre[i-1] + nums1[i]%2 ; 
        }
        // case1 : even
        bool flag = true ; 
        for(int i=0 ; i<n ; i++){
            if(nums1[i]%2 == 1){
                if(i == 0){
                    flag = false ; 
                    break ; 
                }

                int val = pre[i-1] ; 
                if(val == 0){
                    flag = false ; 
                    break ; 
                }
                
            }
        }

        if(flag) return true ; 

        // case2 : odd
        for(int i=0 ; i<n ; i++){
            if(nums1[i]%2 == 0){
                if(i == 0) return false ; 

                int val = pre[i-1] ; 
                if(val == 0) return false ; 
                
            }
        }

        // 2 13 22 

        return true ; 
    }
};