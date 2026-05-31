class Solution {
public:

    const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {

        long long res = 1;

        while (b) {

            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;

            b >>= 1;
        }

        return res;
    }

    int countAnagrams(string s) {

        vector<long long> fact(100005);

        fact[0] = 1;

        for (int i = 1; i < 100005; i++) {

            fact[i] = (fact[i - 1] * i) % MOD;
        }

        stringstream ss(s);

        string word;

        long long ans = 1;

        while (ss >> word) {

            vector<int> freq(26, 0);

            for (char ch : word)
                freq[ch - 'a']++;

            long long ways = fact[word.size()];

            for (int f : freq) {

                if (f > 1) {

                    ways = (ways * power(fact[f], MOD - 2)) % MOD;
                }
            }

            ans = (ans * ways) % MOD;
        }

        return ans;
    }
};