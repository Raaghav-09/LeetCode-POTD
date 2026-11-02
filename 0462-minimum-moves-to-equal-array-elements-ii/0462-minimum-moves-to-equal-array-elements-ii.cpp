class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size() ; 

        sort(nums.begin(),nums.end()) ; 
        /*
        1 2 9 10 
        5 , 4 + 3 + 4 + 5 
        */

        int m1 = (n)/2 , m2 = (n-1)/2 ; 

        int mid = (nums[m1] + nums[m2])/2 ;
        int ans = 0 ; 
        for(int i=0 ; i<n ; i++){   
            ans += abs(nums[i]-mid) ;
        }

        return ans ;
    }
};