class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<long long> dp(amount + 1, 0);

        dp[0] = 1;

        for(int coin : coins) {

            for(int sum = coin; sum <= amount; sum++) {

                dp[sum] += dp[sum - coin];

                // cap to avoid overflow
                if(dp[sum] > INT_MAX)
                    dp[sum] = INT_MAX;
            }
        }

        return dp[amount];
    }
};