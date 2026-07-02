class Solution {
public:
    struct TrieNode {
        TrieNode* child[2];
        int cnt;

        TrieNode() {
            child[0] = child[1] = nullptr;
            cnt = 0;
        }
    };

    TrieNode* root;

    void insert(int num) {
        TrieNode* node = root;

        for (int i = 14; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->child[bit])
                node->child[bit] = new TrieNode();

            node = node->child[bit];
            node->cnt++;
        }
    }

    int query(int num, int limit) {
        if (limit < 0) return 0;

        TrieNode* node = root;
        int ans = 0;

        for (int i = 14; i >= 0; i--) {

            if (!node) break;

            int numBit = (num >> i) & 1;
            int limitBit = (limit >> i) & 1;

            if (limitBit == 1) {

                if (node->child[numBit])
                    ans += node->child[numBit]->cnt;

                node = node->child[1 - numBit];

            } else {

                node = node->child[numBit];

            }
        }

        if (node)
            ans += node->cnt;

        return ans;
    }

    int countPairsLessEqual(vector<int>& nums, int limit) {

        root = new TrieNode();

        int ans = 0;

        for (int num : nums) {
            ans += query(num, limit);
            insert(num);
        }

        return ans;
    }

    int countPairs(vector<int>& nums, int low, int high) {

        return countPairsLessEqual(nums, high) -
               countPairsLessEqual(nums, low - 1);
    }
};