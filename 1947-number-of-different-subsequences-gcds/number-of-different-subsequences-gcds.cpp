class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<bool> present(mx + 1, false);
        for (int x : nums)
            present[x] = true;

        int ans = 0;

        for (int g = 1; g <= mx; g++) {
            int cur = 0;

            for (int mult = g; mult <= mx; mult += g) {
                if (!present[mult]) continue;

                cur = gcd(cur, mult);

                if (cur == g) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};