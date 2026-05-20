class Solution {
public:

    vector<vector<int>> ans;

    void solve(int ind,
               vector<int>& candidates,
               int target,
               vector<int>& temp) {

        // found valid combination
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // out of bounds
        if (ind == candidates.size() || target < 0)
            return;

        // TAKE current element
        temp.push_back(candidates[ind]);

        // stay at same index (reuse allowed)
        solve(ind, candidates,
              target - candidates[ind], temp);

        temp.pop_back();

        // NOT TAKE
        solve(ind + 1, candidates, target, temp);
    }

    vector<vector<int>> combinationSum(
        vector<int>& candidates,
        int target) {

        vector<int> temp;

        solve(0, candidates, target, temp);

        return ans;
    }
};