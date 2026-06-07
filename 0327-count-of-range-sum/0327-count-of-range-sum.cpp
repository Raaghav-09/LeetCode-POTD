class Solution {
public:
    using ll = long long;

    int countRangeSum(vector<int>& nums, int lower, int upper){
        int n = nums.size();

        vector<ll> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }

        multiset<ll> mul;
        mul.insert(0);  // prefix before first element

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            ll low = pre[i] - upper;
            ll high = pre[i] - lower;

            auto l = mul.lower_bound(low);
            auto r = mul.upper_bound(high);

            ans += distance(l, r);

            mul.insert(pre[i]);
        }

        return ans;
    }
};