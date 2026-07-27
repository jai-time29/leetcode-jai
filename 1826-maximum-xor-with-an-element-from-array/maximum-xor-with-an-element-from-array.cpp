class TrieNode {
public:
    TrieNode* child[2];

    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->child[bit])
                node->child[bit] = new TrieNode();

            node = node->child[bit];
        }
    }

    int maxXor(int num) {
        TrieNode* node = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (node->child[1 - bit]) {
                ans |= (1 << i);
                node = node->child[1 - bit];
            } else {
                node = node->child[bit];
            }
        }

        return ans;
    }
};

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i][0], queries[i][1], i});
        }

        sort(q.begin(), q.end(), cmp);

        Trie trie;
        vector<int> ans(queries.size());

        int ptr = 0;
        int n = nums.size();

        for (auto& query : q) {
            int x = query[0];
            int m = query[1];
            int idx = query[2];

            while (ptr < n && nums[ptr] <= m) {
                trie.insert(nums[ptr]);
                ptr++;
            }

            if (ptr == 0)
                ans[idx] = -1;
            else
                ans[idx] = trie.maxXor(x);
        }

        return ans;
    }
};