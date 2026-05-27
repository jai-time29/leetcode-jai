#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int m = isWater.size();
        int n = isWater[0].size();

        queue<pair<int,int>> q;

        vector<vector<int>> height(m, vector<int>(n, -1));

        // All water cells are sources
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (isWater[i][j] == 1) {

                    height[i][j] = 0;

                    q.push({i, j});
                }
            }
        }

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                // Unvisited land cell
                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    height[nr][nc] == -1) {

                    height[nr][nc] = height[r][c] + 1;

                    q.push({nr, nc});
                }
            }
        }

        return height;
    }
};