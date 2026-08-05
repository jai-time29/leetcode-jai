class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<int>& vis) {
        vis[u] = 1;

        for (int v : adj[u]) {
            if (!vis[v])
                dfs(v, adj, vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for (auto &e : invocations)
            adj[e[0]].push_back(e[1]);

        // Find suspicious methods
        vector<int> suspicious(n, 0);
        dfs(k, adj, suspicious);

        // Check if any outside node invokes a suspicious node
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Remove suspicious methods
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};