class Solution {
public:
    vector<vector<int>> dp;

    int solve(string& s, int l, int r) {
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        if(l + 1 == r) return dp[l][r] = 1;

        int bal = 0;
        for(int i = l; i <= r; i++) {
            bal += (s[i] == '(' ? 1 : -1);

            if(bal == 0) {
                if(i == r)
                    return dp[l][r] = 2 * solve(s, l + 1, r - 1);
                return dp[l][r] = solve(s, l, i) + solve(s, i + 1, r);
            }
        }
        return 0;
    }

    int scoreOfParentheses(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(s, 0, n - 1);
    }
};