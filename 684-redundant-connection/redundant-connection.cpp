class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {

        int pu = find(u);
        int pv = find(v);

        if(pu == pv)
            return false; // cycle

        if(rank[pu] < rank[pv])
            swap(pu, pv);

        parent[pv] = pu;

        if(rank[pu] == rank[pv])
            rank[pu]++;

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(
        vector<vector<int>>& edges) {

        int n = edges.size();

        DSU dsu(n);

        for(auto &e : edges) {

            if(!dsu.unite(e[0], e[1])) {
                return e;
            }
        }

        return {};
    }
};