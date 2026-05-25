#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {

        // Path Compression
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    bool unionBySize(int u, int v) {

        int pu = findParent(u);
        int pv = findParent(v);

        // Already in same set
        if (pu == pv)
            return false;

        // Union by Size
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        return true;
    }
};

class Solution {
public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        DSU dsu(n);

        int provinces = n;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                if (isConnected[i][j] == 1) {

                    // If union happens, provinces reduce
                    if (dsu.unionBySize(i, j)) {
                        provinces--;
                    }
                }
            }
        }

        return provinces;
    }
};