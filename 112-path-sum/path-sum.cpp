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

    bool solve(TreeNode* root, int targetSum) {

        if(root == NULL)
            return false;


        // leaf node
        if(root->left == NULL && root->right == NULL) {

            return targetSum == root->val;
        }


        targetSum -= root->val;


        return solve(root->left, targetSum) ||
               solve(root->right, targetSum);
    }


    bool hasPathSum(TreeNode* root, int targetSum) {

        return solve(root, targetSum);
    }
};