class Solution {
public:
    int strangePrinter(string s) {

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for(int i = 0; i < n; i++)
            dp[i][i] = 1;


        for(int len = 2; len <= n; len++) {

            for(int i = 0; i + len <= n; i++) {

                int j = i + len - 1;

                dp[i][j] = len;   // worst case


                for(int k = i; k < j; k++) {

                    int turns = dp[i][k] + dp[k+1][j];


                    if(s[i] == s[k+1])
                        turns--;


                    dp[i][j] = min(dp[i][j], turns);
                }
            }
        }

        return dp[0][n-1];
    }
};