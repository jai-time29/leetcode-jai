class Solution {
public:
    long long dp[501][501][3];

    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        const long long NEG = -4e18;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < 3; k++)
                    dp[i][j][k] = NEG;

        // Starting cell
        if (coins[0][0] >= 0) {
            dp[0][0][0] = coins[0][0];
        } else {
            dp[0][0][0] = coins[0][0]; // don't neutralize
            dp[0][0][1] = 0;           // neutralize
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) continue;

                for (int used = 0; used <= 2; used++) {

                    long long bestPrev = NEG;

                    if (i)
                        bestPrev = max(bestPrev, dp[i-1][j][used]);

                    if (j)
                        bestPrev = max(bestPrev, dp[i][j-1][used]);

                    if (bestPrev == NEG) continue;

                    // Don't neutralize
                    dp[i][j][used] = max(dp[i][j][used],
                                         bestPrev + coins[i][j]);
                }

                if (coins[i][j] < 0) {
                    for (int used = 1; used <= 2; used++) {

                        long long bestPrev = NEG;

                        if (i)
                            bestPrev = max(bestPrev, dp[i-1][j][used-1]);

                        if (j)
                            bestPrev = max(bestPrev, dp[i][j-1][used-1]);

                        if (bestPrev == NEG) continue;

                        // Neutralize robber
                        dp[i][j][used] = max(dp[i][j][used], bestPrev);
                    }
                }
            }
        }

        return max({dp[m-1][n-1][0],
                    dp[m-1][n-1][1],
                    dp[m-1][n-1][2]});
    }
};