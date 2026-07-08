class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        const long long MOD = 1e9 + 7;

        vector<int> pos;              // positions of non-zero digits
        vector<int> digit;            // non-zero digits

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        // prefix digit sum
        vector<long long> prefSum(m + 1, 0);

        // prefix concatenated value
        vector<long long> prefNum(m + 1, 0);

        // powers of 10
        vector<long long> pow10(m + 1, 1);

        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 0; i < m; i++) {
            prefSum[i + 1] = prefSum[i] + digit[i];
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            // first non-zero >= l
            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();

            // first > r
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[R + 1] - prefSum[L];

            int len = R - L + 1;

            long long x =
                (prefNum[R + 1] -
                 prefNum[L] * pow10[len] % MOD+MOD ) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};