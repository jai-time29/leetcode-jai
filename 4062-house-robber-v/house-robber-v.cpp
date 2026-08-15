class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<long long> dp(n, 0);

        dp[0] = nums[0];

        if(colors[0] == colors[1])
            dp[1] = max(nums[0], nums[1]);
        else
            dp[1] = nums[0] + nums[1];

        for(int i = 2; i < n; i++) {

            // Don't take current house
            dp[i] = dp[i - 1];

            // Take current, previous house not taken
            dp[i] = max(dp[i], (long long)nums[i] + dp[i - 2]);

            // Take current and previous house if colors differ
            if(colors[i] != colors[i - 1]) {
                dp[i] = max(dp[i],
                            (long long)nums[i] + dp[i - 1]);
            }
        }

        return dp[n - 1];
    }
};