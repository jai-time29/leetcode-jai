class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx, sy;
        int L = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = L++;
                }
            }
        }

        int fullMask = (1 << L) - 1;

        // bestEnergy[x][y][mask]
        vector<vector<vector<int>>> best(
            m, vector<vector<int>>(
                n, vector<int>(1 << L, -1)
            )
        );

        // x, y, mask, energy
        queue<array<int, 4>> q;

        best[sx][sy][0] = energy;
        q.push({sx, sy, 0, energy});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int steps = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [x, y, mask, e] = q.front();
                q.pop();

                if (mask == fullMask)
                    return steps;

                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nx = x + dr[d];
                    int ny = y + dc[d];

                    if (nx < 0 || nx >= m ||
                        ny < 0 || ny >= n ||
                        classroom[nx][ny] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter
                    if (id[nx][ny] != -1)
                        nmask |= (1 << id[nx][ny]);

                    // Reset
                    if (classroom[nx][ny] == 'R')
                        ne = energy;

                    // Dominance pruning
                    if (ne <= best[nx][ny][nmask])
                        continue;

                    best[nx][ny][nmask] = ne;

                    q.push({nx, ny, nmask, ne});
                }
            }

            steps++;
        }

        return -1;
    }
};