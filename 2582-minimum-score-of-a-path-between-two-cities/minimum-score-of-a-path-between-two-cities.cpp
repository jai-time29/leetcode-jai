/*class Solution {
public:
    int ans = INT_MAX;

    void dfs(int node,
             vector<vector<pair<int,int>>>& adj,
             vector<int>& vis) {

        vis[node] = 1;

        for(auto &[nei, wt] : adj[node]) {

            ans = min(ans, wt);

            if(!vis[nei])
                dfs(nei, adj, vis);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<int> vis(n + 1, 0);

        dfs(1, adj, vis);

        return ans;
    }
};
*/

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 1; i <= n; i++)
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
    int minScore(int n, vector<vector<int>>& roads) {

        DSU dsu(n);

        // Build connected components
        for(auto &road : roads) {
            dsu.unite(road[0], road[1]);
        }

        int root = dsu.find(1);

        int ans = INT_MAX;

        // Find minimum edge in the component of city 1
        for(auto &road : roads) {

            int u = road[0];
            int wt = road[2];

            if(dsu.find(u) == root)
                ans = min(ans, wt);
        }

        return ans;
    }
};