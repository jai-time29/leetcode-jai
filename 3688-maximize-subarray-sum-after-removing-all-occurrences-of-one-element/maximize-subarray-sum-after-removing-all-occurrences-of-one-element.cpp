class Solution {
public:
    long long maxSubarraySum(vector<int>& nums) {
        long long ans = *max_element(nums.begin(), nums.end());

        long long prefix = 0;
        long long minPrefix = 0;
        long long modifiedMinPrefix = 0;

        unordered_map<int, long long> minPrefixPlusRemoval;
        unordered_map<int, int> cnt;

        for (int num : nums) {
            prefix += num;
            ans = max(ans, prefix - modifiedMinPrefix);

            if (num < 0) {
                cnt[num]++;

                if (!minPrefixPlusRemoval.count(num))
                    minPrefixPlusRemoval[num] = min(0LL, minPrefix) + num;
                else
                    minPrefixPlusRemoval[num] =
                        min(minPrefixPlusRemoval[num], minPrefix) + num;

                modifiedMinPrefix = min(
                    modifiedMinPrefix,
                    min(1LL * cnt[num] * num,
                        minPrefixPlusRemoval[num])
                );
            }

            minPrefix = min(minPrefix, prefix);
            modifiedMinPrefix = min(modifiedMinPrefix, minPrefix);
        }

        return ans;
    }
};