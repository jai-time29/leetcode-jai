class Solution {
public:

    int findCheapestPrice(int n,
                          vector<vector<int>>& flights,
                          int src,
                          int dst,
                          int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &f : flights) {

            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> dist(n, INT_MAX);

        queue<pair<int,int>> q;

        q.push({src, 0});

        dist[src] = 0;

        int stops = 0;

        while(!q.empty() && stops <= k) {

            int sz = q.size();

            vector<int> temp = dist;

            while(sz--) {

                auto [node, cost] = q.front();
                q.pop();

                for(auto &[nbr, wt] : adj[node]) {

                    if(cost + wt < temp[nbr]) {

                        temp[nbr] = cost + wt;

                        q.push({nbr, cost + wt});
                    }
                }
            }

            dist = temp;

            stops++;
        }

        return dist[dst] == INT_MAX
               ? -1
               : dist[dst];
    }
};