class Solution {
public:

    int m, n;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int dfs(int r, int c,
            vector<vector<int>>& grid) {

        grid[r][c] = 0;

        int area = 1;

        for(int d = 0; d < 4; d++) {

            int nr = r + dr[d];
            int nc = c + dc[d];

            if(nr >= 0 && nr < m &&
               nc >= 0 && nc < n &&
               grid[nr][nc] == 1) {

                area += dfs(nr, nc, grid);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int maxi = 0;

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {

                    maxi = max(maxi,
                               dfs(i, j, grid));
                }
            }
        }

        return maxi;
    }
};