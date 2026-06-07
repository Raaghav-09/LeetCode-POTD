class Solution {
public:
    using ll = long long ; 
    int countRangeSum(vector<int>& nums , int lower, int upper){
        int n = nums.size() ; 

        vector<ll> pre(n + 1, 0);
        for(int i = 0 ; i < n; i++){
            pre[i + 1] = pre[i] + nums[i];
        }

        auto merge = [&](int l , int mid , int r) -> int{
            int count = 0;
            int start = mid + 1, end = mid + 1;
            
            for(int i = l ; i <= mid ; i++){
                while(start <= r && pre[start] - pre[i] < lower){
                    start++;
                }
                while(end <= r && pre[end] - pre[i] <= upper){
                    end++;
                }
                count += (end - start);
            }
            vector<ll> v(r - l + 1) ; 
            int k = 0 ; 
            int i = l , j = mid + 1; 
            while(i <= mid && j <= r){
                if(pre[i] < pre[j]){
                    v[k] = pre[i] ; 
                    i++ , k++ ; 
                }
                else{
                    v[k] = pre[j] ; 
                    j++ , k++ ; 
                }
            }

            while(i <= mid){
                v[k] = pre[i] ; 
                k++ , i++ ; 
            }

            while(j <= r){
                v[k] = pre[j] ; 
                k++ , j++ ; 
            }

            for(int idx = l ; idx <= r ; idx++){
                pre[idx] = v[idx - l] ; 
            }
            return count ; 
        };

        auto f = [&](auto&& self , int l , int r) -> int {
            if(l >= r){
                 return 0 ; 
            }
            int mid = l + (r - l) / 2 ; 

            int val1 = self(self, l, mid) ; 
            int val2 = self(self, mid + 1, r) ; 

            int val3 = merge(l, mid, r) ;
            return val1 + val2 + val3 ; 
        };

        return f(f, 0, n) ; 
    }
};