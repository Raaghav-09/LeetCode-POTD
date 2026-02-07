class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ans(n, 1); 
        int i = 1;

        while (i < n) {
            // Case 1: Equal Ratings
            // Reset to 1 because we don't need to be higher than the previous
            if (ratings[i] == ratings[i-1]) {
                ans[i] = 1;
                i++;
                continue; 
            }
            
            // Case 2: Increasing Slope
            // Standard forward assignment
            int peak = ans[i-1]; 
            while (i < n && ratings[i] > ratings[i-1]) {
                peak++;
                ans[i] = peak;
                i++;
            }
            
            // Case 3: Decreasing Slope
            // We cannot assign values forward. We must count the length ('down')
            // and then fill them backwards.
            int down = 0;
            while (i < n && ratings[i] < ratings[i-1]) {
                down++;
                i++;
            }
            
            // Backfill the decreasing sequence (assigns 1, 2, 3... backwards)
            for (int k = 0; k < down; k++) {
                ans[i - 1 - k] = k + 1;
            }
            
            // Case 4: Peak Correction
            // The peak (element before the decrease starts) needs to be high enough 
            // to satisfy both the increasing side (existing value) and decreasing side (down + 1).
            if (down > 0) {
                ans[i - 1 - down] = max(ans[i - 1 - down], down + 1);
            }
        }

        return accumulate(ans.begin(), ans.end(), 0); 
    }
};