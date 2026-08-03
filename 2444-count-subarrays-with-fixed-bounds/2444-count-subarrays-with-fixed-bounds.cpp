class Solution {
public:
    using ll = long long ; 
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size() ; 

        deque<int> dq_min , dq_max ; 
        // dq_min is maintaining in ascending order
        // dq_max is maintaining in descending order
        int left = 0 ; 
        ll ans = 0 ; 
        for(int i=0 ; i<n ; i++){
            if(nums[i] > maxK || nums[i] < minK){
                dq_min.clear() ; 
                dq_max.clear() ; 
                left = i+1 ;
                continue ; 
            }
            while(dq_min.size() && nums[dq_min.back()] >= nums[i]){
                dq_min.pop_back() ; 
            }
            dq_min.push_back(i) ; 

            while(dq_max.size() && nums[dq_max.back()] <= nums[i]){
                dq_max.pop_back() ; 
            }
            dq_max.push_back(i) ; 

            if(nums[dq_max.front()] == maxK && nums[dq_min.front()] == minK){
                ans += min(dq_max.front() , dq_min.front()) - left + 1 ; 
            }
        }

        return ans ; 

    }
};