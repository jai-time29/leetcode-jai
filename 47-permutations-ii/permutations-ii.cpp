class Solution {
public:

    void solve(vector<int>& nums, vector<int>& curr,
               vector<int>& used, vector<vector<int>>& ans) {


        // permutation complete
        if(curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }


        for(int i = 0; i < nums.size(); i++) {


            if(used[i])
                continue;


            // duplicate pruning
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1])
                continue;


            used[i] = 1;
            curr.push_back(nums[i]);


            solve(nums, curr, used, ans);


            curr.pop_back();
            used[i] = 0;
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> ans;

        vector<int> curr;

        vector<int> used(nums.size(),0);


        sort(nums.begin(), nums.end());


        solve(nums, curr, used, ans);


        return ans;
    }
};