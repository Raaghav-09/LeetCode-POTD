class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size() ; 
        vector<int> ans ; 
        deque<int> dq ; // stores value of index and monotoincally decreasing
        for(int i=0 ; i<k ; i++){
            while(dq.size() && nums[dq.back()] <= nums[i]){
                dq.pop_back() ; 
            }
            dq.push_back(i) ; 
        }
        ans.push_back(nums[dq.front()]) ; 
        int i = k ; 
        while(i<n){
            int toDelete = i-k ; 
            while(dq.size() && dq.front()<=toDelete){
                dq.pop_front() ; 
            }

            while(dq.size() && nums[dq.back()] <= nums[i]) dq.pop_back() ; 
            dq.push_back(i) ; 
            ans.push_back(nums[dq.front()]) ; 
            i++ ; 
        }

        return ans ; 
    }
};