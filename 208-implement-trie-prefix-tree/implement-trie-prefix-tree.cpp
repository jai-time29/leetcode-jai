class Trie {
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;
            memset(child, 0, sizeof(child));
        }
    };

    Node*root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;

        for(char c : word) {
            int x = c - 'a';

            if(cur->child[x] == nullptr)
                cur->child[x] = new Node();

            cur = cur->child[x];
        }

        cur->isEnd = true;
    }
    
    bool search(string word) {
         Node* cur = root;

        for(char c : word) {
            int x = c - 'a';

            if(cur->child[x] == nullptr)
                return false;

            cur = cur->child[x];
        }

        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
         Node* cur = root;

        for(char c : prefix) {
            int x = c - 'a';

            if(cur->child[x] == nullptr)
                return false;

            cur = cur->child[x];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */