class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++)
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

        if(a == b) return;

        if(size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts) {

        int n = accounts.size();

        DSU dsu(n);

        unordered_map<string,int> emailToAccount;

        // Union accounts sharing emails
        for(int i = 0; i < n; i++) {

            for(int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if(emailToAccount.count(email)) {

                    dsu.unite(
                        i,
                        emailToAccount[email]
                    );
                }
                else {
                    emailToAccount[email] = i;
                }
            }
        }

        // root -> emails
        unordered_map<int, vector<string>> merged;

        for(auto &it : emailToAccount) {

            string email = it.first;
            int acc = it.second;

            int root = dsu.find(acc);

            merged[root].push_back(email);
        }

        vector<vector<string>> ans;

        for(auto &it : merged) {

            int root = it.first;

            vector<string> emails = it.second;

            sort(emails.begin(), emails.end());

            vector<string> curr;

            curr.push_back(accounts[root][0]);

            for(auto &email : emails)
                curr.push_back(email);

            ans.push_back(curr);
        }

        return ans;
    }
};