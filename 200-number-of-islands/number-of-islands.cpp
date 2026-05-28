class Solution {
public:

    int m, n;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void dfs(int r, int c,
             vector<vector<char>>& grid) {

        grid[r][c] = '0';

        for(int d = 0; d < 4; d++) {

            int nr = r + dr[d];
            int nc = c + dc[d];

            if(nr >= 0 && nr < m &&
               nc >= 0 && nc < n &&
               grid[nr][nc] == '1') {

                dfs(nr, nc, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int islands = 0;

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j] == '1') {

                    islands++;

                    dfs(i, j, grid);
                }
            }
        }

        return islands;
    }
};