class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;

        TreeNode* curr = root;

        while (curr) {

            // no left child
            if (curr->left == NULL) {

                ans.push_back(curr->val);

                curr = curr->right;
            }

            else {

                // find predecessor
                TreeNode* pred = curr->left;

                while (pred->right &&
                       pred->right != curr) {

                    pred = pred->right;
                }

                // create thread
                if (pred->right == NULL) {

                    pred->right = curr;

                    curr = curr->left;
                }

                // thread exists
                else {

                    pred->right = NULL;

                    ans.push_back(curr->val);

                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};