#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int r, int c,
             vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        // Mark safe
        board[r][c] = '#';

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for (int d = 0; d < 4; d++) {

            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                board[nr][nc] == 'O') {

                dfs(nr, nc, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        // First and last column
        for (int i = 0; i < m; i++) {

            if (board[i][0] == 'O')
                dfs(i, 0, board);

            if (board[i][n - 1] == 'O')
                dfs(i, n - 1, board);
        }

        // First and last row
        for (int j = 0; j < n; j++) {

            if (board[0][j] == 'O')
                dfs(0, j, board);

            if (board[m - 1][j] == 'O')
                dfs(m - 1, j, board);
        }

        // Convert surrounded O -> X
        // Restore # -> O
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};