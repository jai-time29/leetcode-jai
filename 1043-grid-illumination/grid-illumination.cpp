class Solution {
public:
    unordered_map<int, int> row, col;
    unordered_map<long long, int> diag1, diag2;
    unordered_set<long long> lampsOn;

    vector<int> gridIllumination(int n, vector<vector<int>>& lamps,
                                 vector<vector<int>>& queries) {

        // Initialize lamps
        for (auto &lamp : lamps) {

            int r = lamp[0];
            int c = lamp[1];

            long long key = 1LL * r * n + c;

            if (lampsOn.count(key))
                continue;

            lampsOn.insert(key);

            row[r]++;
            col[c]++;
            diag1[(long long)r - c]++;
            diag2[(long long)r + c]++;
        }

        vector<int> ans;

        int dx[] = {-1,-1,-1,0,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,0,1,-1,0,1};

        for (auto &q : queries) {

            int r = q[0];
            int c = q[1];

            if (row[r] > 0 ||
                col[c] > 0 ||
                diag1[(long long)r - c] > 0 ||
                diag2[(long long)r + c] > 0)
                ans.push_back(1);
            else
                ans.push_back(0);

            // Turn off lamps in 3x3 neighborhood
            for (int k = 0; k < 9; k++) {

                int nr = r + dx[k];
                int nc = c + dy[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                long long key = 1LL * nr * n + nc;

                if (!lampsOn.count(key))
                    continue;

                lampsOn.erase(key);

                row[nr]--;
                col[nc]--;
                diag1[(long long)nr - nc]--;
                diag2[(long long)nr + nc]--;
            }
        }

        return ans;
    }
};