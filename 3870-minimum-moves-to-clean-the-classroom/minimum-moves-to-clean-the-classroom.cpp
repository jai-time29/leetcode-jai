class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        int L = 0;

        // litterId[r][c] = litter number at this cell, or -1
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                }
                else if (classroom[r][c] == 'L') {
                    litterId[r][c] = L++;
                }
            }
        }

        if (L == 0) return 0;

        int fullMask = (1 << L) - 1;

        // state = (r,c,energy,mask)
        // Use a flat array instead of 4D vector
        int states = m * n * (energy + 1) * (1 << L);

        vector<int> dist(states, -1);

        auto id = [&](int r, int c, int e, int mask) {
            return (((r * n + c) * (energy + 1) + e) << L) | mask;
        };

        queue<array<int, 4>> q;

        dist[id(sr, sc, energy, 0)] = 0;
        q.push({sr, sc, energy, 0});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {

            auto [r, c, e, mask] = q.front();
            q.pop();

            int curDist = dist[id(r, c, e, mask)];

            if (mask == fullMask)
                return curDist;

            // If energy is 0, cannot make another move
            if (e == 0)
                continue;

            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n)
                    continue;

                if (classroom[nr][nc] == 'X')
                    continue;

                int ne = e - 1;
                int nmask = mask;

                // O(1) litter check
                if (litterId[nr][nc] != -1) {
                    nmask |= (1 << litterId[nr][nc]);
                }

                // Reset energy
                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }

                int nextId = id(nr, nc, ne, nmask);

                if (dist[nextId] == -1) {
                    dist[nextId] = curDist + 1;
                    q.push({nr, nc, ne, nmask});
                }
            }
        }

        return -1;
    }
};