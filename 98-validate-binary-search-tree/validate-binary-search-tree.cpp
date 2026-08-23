class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> v;

        function<void(TreeNode*)> inorder = [&](TreeNode* root) {
            if (!root) return;

            inorder(root->left);
            v.push_back(root->val);
            inorder(root->right);
        };

        inorder(root);

        for (int i = 1; i < v.size(); i++) {
            if (v[i] <= v[i - 1])
                return false;
        }

        return true;
    }
};