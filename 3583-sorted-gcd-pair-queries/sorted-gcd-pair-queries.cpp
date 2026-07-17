class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int MAX = *max_element(nums.begin(), nums.end());

        vector<long long> freq(MAX + 1, 0);

        for(int x : nums)
            freq[x]++;

        // exact[g] = pairs whose gcd is exactly g
        vector<long long> exact(MAX + 1, 0);

        for(int g = MAX; g >= 1; g--) {

            long long cnt = 0;

            for(int multiple = g; multiple <= MAX; multiple += g)
                cnt += freq[multiple];

            exact[g] = cnt * (cnt - 1) / 2;

            for(int multiple = 2 * g; multiple <= MAX; multiple += g)
                exact[g] -= exact[multiple];
        }

        // prefix sums
        vector<long long> prefix(MAX + 1, 0);

        for(int g = 1; g <= MAX; g++)
            prefix[g] = prefix[g - 1] + exact[g];

        vector<int> ans;

        for(long long k : queries) {

            int gcd =
                lower_bound(prefix.begin() + 1,
                            prefix.end(),
                            k + 1)
                - prefix.begin();

            ans.push_back(gcd);
        }

        return ans;
    }
};