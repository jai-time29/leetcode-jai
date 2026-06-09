class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {

        a = find(a);
        b = find(b);

        if(a == b)
            return;

        if(size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        DSU dsu(n * n);

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        // Build islands
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 0)
                    continue;

                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nr < n &&
                       nc >= 0 && nc < n &&
                       grid[nr][nc] == 1) {

                        int u = r * n + c;
                        int v = nr * n + nc;

                        dsu.unite(u, v);
                    }
                }
            }
        }

        int ans = 0;

        // Try flipping each 0
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 1)
                    continue;

                unordered_set<int> comps;

                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nr < n &&
                       nc >= 0 && nc < n &&
                       grid[nr][nc] == 1) {

                        comps.insert(
                            dsu.find(nr * n + nc)
                        );
                    }
                }

                int curr = 1;

                for(int root : comps)
                    curr += dsu.size[root];

                ans = max(ans, curr);
            }
        }

        // Case: grid already all 1s
        for(int i = 0; i < n*n; i++) {
            if(dsu.find(i) == i)
                ans = max(ans, dsu.size[i]);
        }

        return ans;
    }
};