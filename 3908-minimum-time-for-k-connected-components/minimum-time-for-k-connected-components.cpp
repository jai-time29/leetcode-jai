class DSU {
public:

    vector<int> parent, size;

    DSU(int n) {

        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {

            parent[i] = i;
        }
    }

    int findUPar(int node) {

        if(node == parent[node])
            return node;

        return parent[node] =
            findUPar(parent[node]);
    }

    bool unionBySize(int u, int v) {

        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu == pv)
            return false;

        if(size[pu] < size[pv]) {

            swap(pu, pv);
        }

        parent[pv] = pu;

        size[pu] += size[pv];

        return true;
    }
};

class Solution {
public:

    bool possible(int n,
                  vector<vector<int>>& edges,
                  int k,
                  int t) {

        DSU dsu(n);

        int components = n;

        // Keep only edges with time > t
        for(auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int time = e[2];

            if(time > t) {

                if(dsu.unionBySize(u, v)) {

                    components--;
                }
            }
        }

        return components >= k;
    }

    int minTime(int n,
                vector<vector<int>>& edges,
                int k) {

        // Already enough components
        if(k <= 1) {

            return 0;
        }

        int low = 0;
        int high = 1e9;

        int ans = -1;

        while(low <= high) {

            int mid =
                low + (high - low) / 2;

            if(possible(n, edges, k, mid)) {

                ans = mid;

                high = mid - 1;
            }
            else {

                low = mid + 1;
            }
        }

        return ans;
    }
};