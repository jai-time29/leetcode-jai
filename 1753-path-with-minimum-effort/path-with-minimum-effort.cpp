/*class Solution {
public:

    int m, n;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool bfs(vector<vector<int>>& heights, int limit) {

        vector<vector<int>> vis(m,
            vector<int>(n, 0));

        queue<pair<int,int>> q;

        q.push({0,0});

        vis[0][0] = 1;

        while(!q.empty()) {

            auto [r,c] = q.front();
            q.pop();

            // Reached destination
            if(r == m-1 && c == n-1)
                return true;

            for(int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr >= 0 && nr < m &&
                   nc >= 0 && nc < n &&
                   !vis[nr][nc]) {

                    int diff =
                        abs(heights[r][c]
                        - heights[nr][nc]);

                    if(diff <= limit) {

                        vis[nr][nc] = 1;

                        q.push({nr,nc});
                    }
                }
            }
        }

        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        int low = 0;
        int high = 1e6;

        int ans = 0;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(bfs(heights, mid)) {

                ans = mid;

                high = mid - 1;
            }
            else {

                low = mid + 1;
            }
        }

        return ans;
    }
}; */
class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m,
            vector<int>(n, INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        dist[0][0] = 0;

        pq.push({0, {0,0}});

        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int effort = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Destination reached
            if(r == m-1 && c == n-1)
                return effort;

            for(int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr >= 0 && nr < m &&
                   nc >= 0 && nc < n) {

                    int edgeWeight =
                        abs(heights[r][c]
                        - heights[nr][nc]);

                    int newEffort =
                        max(effort, edgeWeight);

                    if(newEffort < dist[nr][nc]) {

                        dist[nr][nc] = newEffort;

                        pq.push({
                            newEffort,
                            {nr,nc}
                        });
                    }
                }
            }
        }

        return 0;
    }
};