class Solution {
public:
    unordered_map<long long,int> dp;

    int power(long long x) {

        if(x == 1)
            return 0;

        if(dp.count(x))
            return dp[x];

        if(x % 2 == 0)
            return dp[x] = 1 + power(x / 2);

        return dp[x] = 1 + power(3 * x + 1);
    }

    int getKth(int lo, int hi, int k) {

        vector<pair<int,int>> v;

        for(int i = lo; i <= hi; i++)
            v.push_back({power(i), i});

        sort(v.begin(), v.end());

        return v[k - 1].second;
    }
};