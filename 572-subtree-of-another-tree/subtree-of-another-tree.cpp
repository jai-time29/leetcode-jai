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

    bool same(TreeNode* p,
              TreeNode* q) {

        if(p == NULL && q == NULL)
            return true;

        if(p == NULL || q == NULL)
            return false;

        if(p->val != q->val)
            return false;

        return same(p->left, q->left) &&
               same(p->right, q->right);
    }

    bool isSubtree(TreeNode* root,
                   TreeNode* subRoot) {

        if(root == NULL)
            return false;

        // Check current node
        if(same(root, subRoot))
            return true;

        // Search left or right
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};