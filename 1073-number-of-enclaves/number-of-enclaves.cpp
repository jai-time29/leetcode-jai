#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int totalNodes = m * n;

        int exterior = totalNodes;

        vector<vector<int>> adj(totalNodes + 1);

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        // Build graph
        for (int r = 0; r < m; r++) {

            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 0)
                    continue;

                int node = r * n + c;

                // Boundary land -> exterior
                if (r == 0 || c == 0 ||
                    r == m - 1 || c == n - 1) {

                    adj[exterior].push_back(node);
                    adj[node].push_back(exterior);
                }

                // Adjacent land connections
                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int neigh = nr * n + nc;

                        adj[node].push_back(neigh);
                    }
                }
            }
        }

        // BFS from exterior
        vector<int> vis(totalNodes + 1, 0);

        queue<int> q;

        q.push(exterior);

        vis[exterior] = 1;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int neigh : adj[node]) {

                if (!vis[neigh]) {

                    vis[neigh] = 1;

                    q.push(neigh);
                }
            }
        }

        // Count unreachable land cells
        int count = 0;

        for (int r = 0; r < m; r++) {

            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 1) {

                    int node = r * n + c;

                    if (!vis[node])
                        count++;
                }
            }
        }

        return count;
    }
};