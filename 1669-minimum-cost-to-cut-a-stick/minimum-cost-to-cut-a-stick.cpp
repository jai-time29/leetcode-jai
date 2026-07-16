class Solution {
public:
    int minCost(int n, vector<int>& cuts) {

        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int c = cuts.size() - 2;

        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        for(int len = 1; len <= c; len++){

            for(int i = 1; i + len - 1 <= c; i++){

                int j = i + len - 1;

                dp[i][j] = INT_MAX;

                for(int k = i; k <= j; k++){

                    dp[i][j] = min(dp[i][j],
                                   cuts[j+1] - cuts[i-1]
                                   + dp[i][k-1]
                                   + dp[k+1][j]);
                }
            }
        }

        return dp[1][c];
    }
};