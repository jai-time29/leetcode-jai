
//visited array method
/*class Solution {
public:

    vector<vector<int>> ans;

    void solve(vector<int>& nums,
               vector<int>& temp,
               vector<bool>& vis) {

        // permutation complete
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // already used
            if (vis[i])
                continue;

            vis[i] = true;

            temp.push_back(nums[i]);

            solve(nums, temp, vis);

            temp.pop_back();

            vis[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> temp;

        vector<bool> vis(nums.size(), false);

        solve(nums, temp, vis);

        return ans;
    }
}; */
//SWAP method
class Solution {
public:

    vector<vector<int>> ans;

    void solve(int ind,
               vector<int>& nums) {

        if (ind == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = ind;
             i < nums.size();
             i++) {

            swap(nums[ind], nums[i]);

            solve(ind + 1, nums);

            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permute(
        vector<int>& nums) {

        solve(0, nums);

        return ans;
    }
};