class Solution {
public:

    void dfs(int r, int c,
             vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        grid[r][c] = 0;

        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};

        for(int d = 0; d < 4; d++) {

            int nr = r + dr[d];
            int nc = c + dc[d];

            if(nr >= 0 && nr < m &&
               nc >= 0 && nc < n &&
               grid[nr][nc] == 1) {

                dfs(nr, nc, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Boundary traversal

        for(int i = 0; i < m; i++) {

            if(grid[i][0] == 1)
                dfs(i,0,grid);

            if(grid[i][n-1] == 1)
                dfs(i,n-1,grid);
        }

        for(int j = 0; j < n; j++) {

            if(grid[0][j] == 1)
                dfs(0,j,grid);

            if(grid[m-1][j] == 1)
                dfs(m-1,j,grid);
        }

        int count = 0;

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};