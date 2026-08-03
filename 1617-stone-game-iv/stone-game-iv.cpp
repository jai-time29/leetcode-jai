class Solution {
public:
    bool winnerSquareGame(int n) {

        vector<bool> dp(n + 1, false);

        dp[0] = false;

        for (int stones = 1; stones <= n; stones++) {

            for (int i = 1; i * i <= stones; i++) {

                if (!dp[stones - i * i]) {
                    dp[stones] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};