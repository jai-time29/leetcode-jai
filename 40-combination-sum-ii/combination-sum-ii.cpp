class Solution {
public:

    vector<vector<int>> ans;

    void solve(int ind,
               vector<int>& candidates,
               int target,
               vector<int>& temp) {

        // valid combination
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = ind;
             i < candidates.size();
             i++) {

            // skip duplicates
            if (i > ind &&
                candidates[i] == candidates[i - 1])
                continue;

            // pruning
            if (candidates[i] > target)
                break;

            temp.push_back(candidates[i]);

            // move to next index
            solve(i + 1,
                  candidates,
                  target - candidates[i],
                  temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(
        vector<int>& candidates,
        int target) {

        sort(candidates.begin(),
             candidates.end());

        vector<int> temp;

        solve(0, candidates,
              target, temp);

        return ans;
    }
};