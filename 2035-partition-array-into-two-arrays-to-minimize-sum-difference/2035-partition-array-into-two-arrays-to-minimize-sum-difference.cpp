class Solution {
public:
    using ll = long long ; 
    int minimumDifference(vector<int>& nums) {
        int m = nums.size() ; 
        int n = m/2 ; 
        vector<vector<ll>> left(n+1) ; 
        vector<vector<ll>> right(n+1) ; 

        for(int mask = 0 ; mask < (1<<n) ; mask++){
            int sum = 0 ; 
            int cnt = 0 ; 
            for(int i=0 ; i<n ; i++){
                if((mask >> i) & 1){
                    sum += nums[i] ; 
                    cnt++ ; 
                }
            }
            left[cnt].push_back(sum) ; 
        }

        for(int mask = 0 ; mask < (1<<n) ; mask++){
            int sum = 0 ; 
            int cnt = 0 ; 
            for(int i=0 ; i<n ; i++){
                if((mask >> i) & 1){
                    sum += nums[i+n] ; 
                    cnt++ ; 
                }
            }
            right[cnt].push_back(sum) ; 
        }

        for(int cnt = 0 ; cnt <=n ; cnt++){
            // sort(left[cnt].begin(),left[cnt].end()) ; 
            sort(right[cnt].begin(),right[cnt].end()) ; 
        }

        ll totalSum = accumulate(nums.begin(),nums.end(),0LL) ; 
        ll ans = INT_MAX ; 
        for(int cnt=0 ; cnt<=n ; cnt++){
            int l = cnt , r = n-cnt ; 

            for(auto ele : left[l]){
                // sum - ele - x => to be minimum
                // i know sum-ele now (sum - ele = y)
                // and i want to minimize the abs(sum-ele-x)
                // y - x , x - y 

                // y - x ; 
                ll target = (totalSum/2 - ele) ; 
                int lb = lower_bound(right[r].begin(),right[r].end(),target) - right[r].begin() ; // idx

                if(lb == right[r].size()){
                    lb-- ; 
                }

                ans = min(ans , llabs(totalSum-2*ele-2*right[r][lb])) ; 
                if(lb - 1 >= 0) ans = min(ans , llabs(totalSum-2*ele-2*right[r][lb-1])) ; 
            }
        }

        return ans ; 
    }
};