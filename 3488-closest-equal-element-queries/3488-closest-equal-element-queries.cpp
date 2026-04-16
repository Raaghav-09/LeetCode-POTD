class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }
        vector<int> ans;
        for (int idx : queries) {
            int value = nums[idx];
            vector<int>& positions = m[value];
            if (positions.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            auto it = lower_bound(positions.begin(), positions.end(), idx);
            int posIndex = it - positions.begin();
            int k = positions.size();
            int left = positions[(posIndex - 1 + k) % k];
            int right = positions[(posIndex + 1) % k];
            
            int d1 = abs(idx - left);
            int d2 = abs(right - idx);
            d1 = min(d1, n - d1);
            d2 = min(d2, n - d2);
            
            ans.push_back(min(d1, d2));
        }
        return ans;
    }
};
