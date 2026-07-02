class Solution {
public:
    vector<int> dp;

    int solve(int i, vector<vector<int>>& offers, vector<int>& starts) {

        if (i >= offers.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // Skip
        int ans = solve(i + 1, offers, starts);

        // Take
        int next = lower_bound(starts.begin(), starts.end(),
                               offers[i][1] + 1) - starts.begin();

        ans = max(ans,
                  offers[i][2] + solve(next, offers, starts));

        return dp[i] = ans;
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {

        sort(offers.begin(), offers.end());

        vector<int> starts;

        for (auto &x : offers)
            starts.push_back(x[0]);

        dp.assign(offers.size(), -1);

        return solve(0, offers, starts);
    }
};