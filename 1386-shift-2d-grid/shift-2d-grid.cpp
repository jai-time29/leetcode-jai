class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int N = m * n;

        k %= N;
        if (k == 0) return grid;

        int moved = 0;

        for (int start = 0; moved < N; start++) {
            int curr = start;

            int r = curr / n;
            int c = curr % n;
            int prev = grid[r][c];

            do {
                int next = (curr + k) % N;

                int nr = next / n;
                int nc = next % n;

                swap(prev, grid[nr][nc]);

                curr = next;
                moved++;

            } while (curr != start);
        }

        return grid;
    }
};