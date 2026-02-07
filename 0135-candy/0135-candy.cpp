class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ans(n, 1); 
        int i = 1;

        while (i < n) {
            // Case 1: Equal Ratings
            if (ratings[i] == ratings[i-1]) {
                ans[i] = 1;
                i++;
                continue; 
            }
            
            // Case 2: Increasing Slope
            int peak = ans[i-1]; 
            while (i < n && ratings[i] > ratings[i-1]) {
                peak++;
                ans[i] = peak;
                i++;
            }
            
            // Case 3: Decreasing Slope
            int down = 0;
            while (i < n && ratings[i] < ratings[i-1]) {
                down++;
                i++;
            }
            
            for (int k = 0; k < down; k++) {
                ans[i - 1 - k] = k + 1;
            }

            // Case 4: Peak Correction
            if (down > 0) {
                ans[i - 1 - down] = max(ans[i - 1 - down], down + 1);
            }
        }

        return accumulate(ans.begin(), ans.end(), 0); 
    }
};