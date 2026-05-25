#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;

        // Store all rotten oranges
        // Count fresh oranges
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // No fresh oranges
        if (fresh == 0)
            return 0;

        int minutes = 0;

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while (!q.empty()) {

            int size = q.size();

            bool rottenThisMinute = false;

            for (int k = 0; k < size; k++) {

                auto [r, c] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Valid fresh orange
                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;

                        q.push({nr, nc});

                        fresh--;

                        rottenThisMinute = true;
                    }
                }
            }

            // Increase minute only if something rotted
            if (rottenThisMinute)
                minutes++;
        }

        // Still fresh oranges left
        if (fresh > 0)
            return -1;

        return minutes;
    }
};