#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int r, int c,
             vector<vector<int>>& image,
             int oldColor,
             int newColor) {

        int m = image.size();
        int n = image[0].size();

        // Color current cell
        image[r][c] = newColor;

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for (int d = 0; d < 4; d++) {

            int nr = r + dr[d];
            int nc = c + dc[d];

            // Valid cell with original color
            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                image[nr][nc] == oldColor) {

                dfs(nr, nc, image, oldColor, newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int oldColor = image[sr][sc];

        // Important edge case
        if (oldColor == color)
            return image;

        dfs(sr, sc, image, oldColor, color);

        return image;
    }
};