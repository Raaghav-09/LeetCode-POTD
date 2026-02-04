class Solution {
public:
    vector<tuple<int, int, long long> > decompose(vector<int>& nums){
        int n = (int)nums.size();
        vector<tuple<int, int, long long> > subarrays;

        int l = 0;
        long long sum = nums[0];
        
        for(int i = 1; i < n; i ++){
            // If we fail strict decreasing at boundary i-1 -> i, end the current subarray.
            if(nums[i - 1] <= nums[i]){
                subarrays.push_back({l, i - 1, sum});
                l = i;
                sum = 0;
            }
            sum += nums[i];
        }
        //last subarray
        subarrays.push_back({l, n - 1, sum});
        return subarrays;
    }
    long long maxSumTrionic(vector<int>& nums) {
        // int n = nums.size();

        // vector<int> track(n, 0) ;

        // for (int i = 1; i < n - 1; i++) {
        //     if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
        //         track[i] = 1;        
        //     } 
        //     else if (nums[i - 1] > nums[i] && nums[i] > nums[i + 1]) {
        //         track[i] = -1;        
        //     } 
        //     else if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
        //         track[i] = 2;   
        //     } 
        //     else if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
        //         track[i] = -2;     
        //     }
        // }

        // if (nums[0] < nums[1]) track[0] = 1;
        // else if (nums[0] > nums[1]) track[0] = -1;

        // if (nums[n - 2] < nums[n - 1]) track[n - 1] = 1;
        // else if (nums[n - 2] > nums[n - 1]) track[n - 1] = -1;

        // vector<vector<int>> v ;

        // int i = 0;
        // while (i < n) {
        //     if (track[i] != 1) {
        //         i++;
        //         continue;
        //     }

        //     int l, p, q, r = -1;
        //     int j = i;

        //     // first increasing
        //     bool inc_st = false;
        //     l = j;
        //     while (j < n && track[j] == 1) {
        //         inc_st = true;
        //         j++;
        //     }

        //     // peak up
        //     p = j;
        //     if (j >= n || track[j] != 2) {
        //         i = j;
        //         continue;
        //     }

        //     // decreasing
        //     j++;
        //     while (j < n && track[j] == -1) {
        //         j++;
        //     }
        //     q = j;

        //     // peak down
        //     if (j >= n || track[j] != -2) {
        //         i = j;
        //         continue;
        //     }

        //     // second increasing
        //     bool inc_en = false;
        //     j++;
        //     while (j < n && track[j] == 1) {
        //         inc_en = true;
        //         r = j;
        //         j++;
        //     }

        //     if (!(inc_st && inc_en)) {
        //         i = j;
        //         continue;
        //     }

        //     v.push_back({l, p, q, r});
        //     i = j;   
        // }

        // vector<long long> prefix(n,0) , suffix(n,0) ; 
        // prefix[0] = nums[0] ; 
        // for(int i=1 ; i<n ; i++){
        //     prefix[i] = prefix[i-1] + nums[i] ; 
        // }

        // for(int i=n-2 ; i>=0 ; i--){
        //     suffix[i] = suffix[i+1] + nums[i] ; 
        // }

        // long long ans = INT_MIN ; 
        // for(vector<int> part : v){
        //     int l = part[0] , p = part[1] , q = part[2] , r = part[3] ; 
        //     long long res = prefix[q+1] - prefix[p] ; 
        //     long long first_inc = 0 ; 
        //     long long mx_first_inc = 0 ; 
        //     for(int j=p ; j>=l ; j--){
        //         first_inc += nums[j] ; 
        //         mx_first_inc = max(mx_first_inc , first_inc) ;
        //     }
        //     res += mx_first_inc ; 

        //     long long sec_inc = 0 ; 
        //     long long mx_sec_inc = 0 ; 
        //     for(int j=q ; j<=r ; j++){
        //         sec_inc += nums[j] ; 
        //         mx_sec_inc = max(sec_inc , mx_sec_inc) ; 
        //     }

        //     res += mx_sec_inc ;

        //     ans = max(res , ans) ; 
        // }

        // return ans ; 

        int n = (int)nums.size();
        long long maxEndingAt[n];
        for(int i = 0; i < n; i ++){
            maxEndingAt[i] = nums[i];
            if(i > 0 && nums[i - 1] < nums[i]){
                if(maxEndingAt[i - 1] > 0){
                    maxEndingAt[i] += maxEndingAt[i - 1];
                }
            }
        }
        long long maxStartingAt[n];
        for(int i = n - 1; i >= 0; i --){
            maxStartingAt[i] = nums[i];
            if(i < n - 1 && nums[i] < nums[i + 1]){
                if(maxStartingAt[i + 1] > 0){
                    maxStartingAt[i] += maxStartingAt[i + 1];
                }
            }
        }
        vector<tuple<int, int, long long> > PQS = decompose(nums);
        long long ans = LLONG_MIN;
        for(auto [p, q, sum] : PQS){
            
            if(p > 0 && nums[p-1] < nums[p] &&
               q < n - 1 && nums[q] < nums[q + 1] &&
               p < q){
                ans = max(ans, maxEndingAt[p-1] + sum + maxStartingAt[q+1]);
            }
        }
        return ans;

    }
};
