#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long INF = 1e18;

    long long solve(int i, int j,
                    vector<int>& robot,
                    vector<vector<int>>& factory,
                    vector<vector<long long>>& dp) {

        // All robots repaired
        if (i == robot.size())
            return 0;

        // No factories left
        if (j == factory.size())
            return INF;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long ans = solve(i, j + 1, robot, factory, dp);

        long long cost = 0;

        int pos = factory[j][0];
        int limit = factory[j][1];

        // Assign k robots to current factory
        for (int k = 1;
             k <= limit && i + k - 1 < robot.size();
             k++) {

            cost += abs(robot[i + k - 1] - pos);

            ans = min(ans,
                      cost +
                      solve(i + k, j + 1,
                            robot, factory, dp));
        }

        return dp[i][j] = ans;
    }

    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {

        sort(robot.begin(), robot.end());

        sort(factory.begin(), factory.end());

        int R = robot.size();
        int F = factory.size();

        vector<vector<long long>> dp(
            R + 1,
            vector<long long>(F + 1, -1)
        );

        return solve(0, 0, robot, factory, dp);
    }
};