class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n);

        for (auto& [ele, v] : mp) {
            int m = v.size();  // size of this group

            vector<long long> p(m);
            p[0] = v[0];
            for (int i = 1; i < m; i++) {
                p[i] = p[i - 1] + v[i];
            }

            for (int i = 0; i < m; i++) {
                long long val = (p[m - 1] - p[i]) - 1LL * (m - 1 - i) * v[i];
                if (i > 0) {
                    val += 1LL * i * v[i] - p[i - 1];
                }
                ans[v[i]] = val;
            }
        }

        return ans;
    }
};