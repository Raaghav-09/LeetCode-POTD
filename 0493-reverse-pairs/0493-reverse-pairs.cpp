class Solution {
public:
    int merge(int i , int mid , int j , vector<int>& nums){
        vector<int> v ;
        int ans = 0 ; 
        for(int idx=mid+1 ; idx<=j ; idx++){
            long long num = 2LL*nums[idx] ; 
            int ub = upper_bound(nums.begin()+i,nums.begin()+mid+1,num) - (nums.begin() + i) ; 
            int res = mid-i+1 - ub ; 
            ans += res ; 
        }
        int n1 = mid - i + 1 , n2 = j - mid ; 
        vector<int> left(n1) , right(n2) ; 

        for(int idx=0 ; idx<n1 ; idx++) left[idx] = nums[i+idx] ; 
        for(int idx=0 ; idx<n2 ; idx++) right[idx] = nums[mid+1+idx] ; 

        int idx1 = 0 , idx2 = 0 ; 
        int idx = i ; 
        while(idx1<n1 && idx2<n2){
            if(left[idx1] <= right[idx2]){
                nums[idx] = left[idx1] ; 
                idx++ , idx1++ ;
            }
            else{
                nums[idx] = right[idx2] ; 
                idx2++ , idx++ ; 
            }
        }

        while(idx1<n1){
            nums[idx] = left[idx1] ; 
            idx++ ; 
            idx1++ ; 
        }

        while(idx2<n2){
            nums[idx] = right[idx2] ; 
            idx++ ; 
            idx2++ ; 
        }

        return ans ; 
    }
    int check(int i, int j , vector<int>& nums){
        if(i >= j) return 0 ; 
        int mid = (i+j)/2 ; 

        int cnt1 = check(i,mid,nums) ; 
        int cnt2 = check(mid+1,j,nums) ; 
        int cnt = merge(i,mid,j,nums) ; 
        return cnt1 + cnt2 + cnt ; 
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size() ;

        return check(0,n-1,nums) ; 
    }
};