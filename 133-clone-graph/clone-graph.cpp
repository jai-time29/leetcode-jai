class Solution {
public:

    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {

        if (!node)
            return nullptr;

        mp.reserve(101);

        return dfs(node);
    }

    Node* dfs(Node* node) {

        auto it = mp.find(node);

        if (it != mp.end())
            return it->second;

        Node* clone = new Node(node->val);

        mp[node] = clone;

        clone->neighbors.reserve(node->neighbors.size());

        for (Node* neigh : node->neighbors) {

            clone->neighbors.push_back(
                dfs(neigh)
            );
        }

        return clone;
    }
};