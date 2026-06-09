/* class Solution {
public:

    void dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& vis) {

        vis[node] = 1;

        for(int nei : adj[node]) {
            if(!vis[nei])
                dfs(nei, adj, vis);
        }
    }

    int makeConnected(int n,
                      vector<vector<int>>& connections) {

        if(connections.size() < n-1)
            return -1;

        vector<vector<int>> adj(n);

        for(auto &e : connections) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);

        int components = 0;

        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                components++;
                dfs(i,adj,vis);
            }
        }

        return components - 1;
    }
}; */

class Solution {
public:

    vector<int> parent, rankv;

    int find(int x) {
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {

        a = find(a);
        b = find(b);

        if(a == b) return;

        if(rankv[a] < rankv[b])
            swap(a,b);

        parent[b] = a;

        if(rankv[a] == rankv[b])
            rankv[a]++;
    }

    int makeConnected(int n,
                      vector<vector<int>>& connections) {

        if(connections.size() < n-1)
            return -1;

        parent.resize(n);
        rankv.resize(n,0);

        for(int i=0;i<n;i++)
            parent[i]=i;

        for(auto &e : connections)
            unite(e[0], e[1]);

        int components = 0;

        for(int i=0;i<n;i++) {
            if(find(i) == i)
                components++;
        }

        return components - 1;
    }
};