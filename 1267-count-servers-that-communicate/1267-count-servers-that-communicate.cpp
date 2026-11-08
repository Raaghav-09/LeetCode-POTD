class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows(m, 0), col(n, 0);

        // Count the number of servers in each row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rows[i]++;
                    col[j]++;
                }
            }
        }

        int ans = 0;

        // Traverse the grid again to count servers that are connected
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && (rows[i] > 1 || col[j] > 1)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
