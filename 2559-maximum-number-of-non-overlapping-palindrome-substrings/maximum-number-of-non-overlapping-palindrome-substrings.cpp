class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Precompute palindromes
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                if (s[l] == s[r] &&
                    (len <= 2 || pal[l + 1][r - 1]))
                    pal[l][r] = true;
            }
        }

        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {
            // Don't take a palindrome ending at i
            if (i > 0)
                dp[i] = dp[i - 1];

            // Take palindrome [j...i]
            for (int j = i-k+1; j >= 0; j--) {

        if (pal[j][i]) {
            dp[i] = max(dp[i],
                        (j > 0 ? dp[j-1] : 0) + 1);
            break;
        }
    }
        }

        return dp[n - 1];
    }
};