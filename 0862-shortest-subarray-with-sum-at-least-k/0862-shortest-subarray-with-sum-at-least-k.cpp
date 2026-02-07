class Solution {
public:
    // Logic : After having prefix sum , for every R , we have to find index L such that prefix of that index L is minimum across all them (0 to R-1), Once you find that index L , remove that index as for that particular index you have already got the best possible R
    // There are two ways to solve this , one is using set => O(n log(n)) , second is using deque/queue optimization => O(n)
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size() ; 
        vector<long long> prefix(n + 1 , 0) ; 

        for(int i=1 ; i<=n ; i++){
            prefix[i] = prefix[i-1] + nums[i-1] ; 
        }
        int ans = n + 1 ; 
        deque<int> dq ; 
        for(int i=0 ; i<=n ; i++){
            while(dq.size() && prefix[i]-prefix[dq.front()] >= k){
                ans = min(ans , i - dq.front()) ; 
                dq.pop_front() ; 
            }

            while(dq.size() && prefix[i] <= prefix[dq.back()]){
                dq.pop_back() ; 
            }

            dq.push_back(i) ; 
        }

        return ans == n+1 ? -1 : ans ; 
    }
};