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

    int height(TreeNode* root) {

        if (!root)
            return -1;

        return 1 + max(
            height(root->left),
            height(root->right)
        );
    }

    void dfs(TreeNode* root,
             vector<vector<string>>& res,
             int row,
             int left,
             int right) {

        if (!root || left > right)
            return;

        int mid =
            left + (right - left) / 2;

        res[row][mid] =
            to_string(root->val);

        dfs(root->left,
            res,
            row + 1,
            left,
            mid - 1);

        dfs(root->right,
            res,
            row + 1,
            mid + 1,
            right);
    }

    vector<vector<string>>
    printTree(TreeNode* root) {

        int h = height(root);

        int rows = h + 1;

        int cols = (1 << (h + 1)) - 1;

        vector<vector<string>> res(
            rows,
            vector<string>(cols, "")
        );

        dfs(root,
            res,
            0,
            0,
            cols - 1);

        return res;
    }
};