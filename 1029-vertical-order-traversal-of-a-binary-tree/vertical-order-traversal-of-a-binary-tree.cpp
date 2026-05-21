class Solution {
public:

    vector<vector<int>>
    verticalTraversal(TreeNode* root) {

        map<int,
            map<int,
                multiset<int>>> mp;

        queue<pair<TreeNode*,
              pair<int,int>>> q;

        q.push({root, {0,0}});

        while (!q.empty()) {

            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;

            int row = front.second.first;
            int col = front.second.second;

            mp[col][row].insert(node->val);

            if (node->left) {

                q.push({
                    node->left,
                    {row + 1, col - 1}
                });
            }

            if (node->right) {

                q.push({
                    node->right,
                    {row + 1, col + 1}
                });
            }
        }

        vector<vector<int>> ans;

        for (auto colPair : mp) {

            vector<int> temp;

            for (auto rowPair :
                 colPair.second) {

                temp.insert(
                    temp.end(),
                    rowPair.second.begin(),
                    rowPair.second.end()
                );
            }

            ans.push_back(temp);
        }

        return ans;
    }
};