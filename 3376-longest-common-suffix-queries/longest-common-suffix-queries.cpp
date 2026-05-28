class Solution {
public:

    struct Node {

        int child[26];
        int bestIdx;

        Node() {

            memset(child, -1, sizeof(child));

            bestIdx = -1;
        }
    };

    vector<Node> trie;

    vector<string> words;

    Solution() {

        trie.push_back(Node()); // root
    }

    bool better(int i, int j) {

        if (j == -1)
            return true;

        if (words[i].size() < words[j].size())
            return true;

        if (words[i].size() == words[j].size() && i < j)
            return true;

        return false;
    }

    void insert(string s, int idx) {

        reverse(s.begin(), s.end());

        int node = 0;

        if (better(idx, trie[node].bestIdx))
            trie[node].bestIdx = idx;

        for (char ch : s) {

            int c = ch - 'a';

            if (trie[node].child[c] == -1) {

                trie[node].child[c] = trie.size();

                trie.push_back(Node());
            }

            node = trie[node].child[c];

            if (better(idx, trie[node].bestIdx))
                trie[node].bestIdx = idx;
        }
    }

    int query(string s) {

        reverse(s.begin(), s.end());

        int node = 0;

        for (char ch : s) {

            int c = ch - 'a';

            if (trie[node].child[c] == -1)
                break;

            node = trie[node].child[c];
        }

        return trie[node].bestIdx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        words = wordsContainer;

        for (int i = 0; i < wordsContainer.size(); i++) {

            insert(wordsContainer[i], i);
        }

        vector<int> ans;

        for (auto &q : wordsQuery) {

            ans.push_back(query(q));
        }

        return ans;
    }
};