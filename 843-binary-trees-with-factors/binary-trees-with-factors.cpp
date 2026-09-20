class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        sort(arr.begin(), arr.end());

        int n = arr.size();
        unordered_map<long long, int> mp;

        for (int i = 0; i < n; i++)
            mp[arr[i]] = i;

        vector<long long> dp(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {

                if (arr[i] % arr[j] != 0)
                    continue;

                long long other = arr[i] / arr[j];

                if (!mp.count(other))
                    continue;

                int k = mp[other];

                if (j > k)
                    continue;

                if (j == k)
                    dp[i] += dp[j] * dp[k];
                else
                    dp[i] += 2 * dp[j] * dp[k];

                dp[i] %= MOD;
                cout<<dp[i];
            }
        }

        long long ans = 0;

        for (long long x : dp)
            ans = (ans + x) % MOD;

        return ans;
    }
};