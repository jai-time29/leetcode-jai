class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while(!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int cost = cur[0];
            int r = cur[1];
            int c = cur[2];

            if(r == n-1 && c == n-1)
                return cost;

            if(cost > dist[r][c])
                continue;

            for(int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                int newCost = max(cost, grid[nr][nc]);

                if(newCost < dist[nr][nc]) {

                    dist[nr][nc] = newCost;
                    pq.push({newCost, nr, nc});
                }
            }
        }

        return -1;
    }
};