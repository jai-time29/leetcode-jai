class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        // Optimization
        if(k >= m + n - 2)
            return m + n - 2;

        queue<vector<int>> q;

        vector<vector<vector<bool>>> vis(
            m,
            vector<vector<bool>>(n,
                vector<bool>(k + 1, false)));

        q.push({0, 0, k, 0});

        vis[0][0][k] = true;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(!q.empty()) {

            auto cur = q.front();
            q.pop();

            int r = cur[0];
            int c = cur[1];
            int rem = cur[2];
            int steps = cur[3];

            if(r == m - 1 && c == n - 1)
                return steps;

            for(int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr < 0 || nr >= m ||
                   nc < 0 || nc >= n)
                    continue;

                int newRem = rem - grid[nr][nc];

                if(newRem >= 0 &&
                   !vis[nr][nc][newRem]) {

                    vis[nr][nc][newRem] = true;

                    q.push({nr, nc,
                            newRem,
                            steps + 1});
                }
            }
        }

        return -1;
    }
};