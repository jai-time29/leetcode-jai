class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        const int NEG = -1e9;

        vector<vector<int>> dp(n, vector<int>(n, NEG));
        dp[0][0] = grid[0][0];

        for (int k = 1; k <= 2 * n - 2; k++) {
            vector<vector<int>> ndp(n, vector<int>(n, NEG));

            for (int r1 = 0; r1 < n; r1++) {
                int c1 = k - r1;
                if (c1 < 0 || c1 >= n || grid[r1][c1] == -1) continue;

                for (int r2 = 0; r2 < n; r2++) {
                    int c2 = k - r2;
                    if (c2 < 0 || c2 >= n || grid[r2][c2] == -1) continue;

                    int best = dp[r1][r2];

                    if (r1 > 0) best = max(best, dp[r1 - 1][r2]);
                    if (r2 > 0) best = max(best, dp[r1][r2 - 1]);
                    if (r1 > 0 && r2 > 0)
                        best = max(best, dp[r1 - 1][r2 - 1]);

                    if (best == NEG) continue;

                    int cherries = grid[r1][c1];
                    if (r1 != r2)
                        cherries += grid[r2][c2];

                    ndp[r1][r2] = best + cherries;
                }
            }

            dp = ndp;
        }

        return max(0, dp[n - 1][n - 1]);
    }
};