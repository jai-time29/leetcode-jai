class Solution {
public:

    int m, n;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void dfs(int r, int c,
             vector<vector<int>>& heights,
             vector<vector<int>>& vis) {

        vis[r][c] = 1;

        for(int d = 0; d < 4; d++) {

            int nr = r + dr[d];
            int nc = c + dc[d];

            // Reverse flow:
            // move only to greater/equal height

            if(nr >= 0 && nr < m &&
               nc >= 0 && nc < n &&
               !vis[nr][nc] &&
               heights[nr][nc] >= heights[r][c]) {

                dfs(nr, nc, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(
        vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> pacific(m,
            vector<int>(n, 0));

        vector<vector<int>> atlantic(m,
            vector<int>(n, 0));

        // Pacific DFS
        // top row
        for(int j = 0; j < n; j++) {

            dfs(0, j, heights, pacific);
        }

        // left column
        for(int i = 0; i < m; i++) {

            dfs(i, 0, heights, pacific);
        }

        // Atlantic DFS
        // bottom row
        for(int j = 0; j < n; j++) {

            dfs(m - 1, j, heights, atlantic);
        }

        // right column
        for(int i = 0; i < m; i++) {

            dfs(i, n - 1, heights, atlantic);
        }

        vector<vector<int>> ans;

        // Cells reachable by BOTH oceans
        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(pacific[i][j] &&
                   atlantic[i][j]) {

                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};