/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> ans;
    unordered_set<int> del;

    TreeNode* dfs(TreeNode* root, bool isRoot) {
        if (!root) return nullptr;

        bool deleted = del.count(root->val);

        if (isRoot && !deleted)
            ans.push_back(root);

        root->left = dfs(root->left, deleted);
        root->right = dfs(root->right, deleted);

        return deleted ? nullptr : root;
    }

    vector<TreeNode*> delNodes(TreeNode* root,
                               vector<int>& to_delete) {

        del = unordered_set<int>(
            to_delete.begin(),
            to_delete.end()
        );

        dfs(root, true);

        return ans;
    }
};