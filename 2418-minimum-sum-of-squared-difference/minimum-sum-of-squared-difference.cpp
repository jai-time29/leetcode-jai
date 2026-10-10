class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> diff(n);
        int low = 0, high = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            high = max(high, diff[i]);
        }

        // If all differences can be eliminated
        long long total = 0;
        for (int d : diff) total += d;

        if (k >= total) return 0;

        // Binary search the minimum maximum difference
        while (low < high) {
            int mid = low + (high - low) / 2;
            long long ops = 0;

            for (int d : diff) {
                if (d > mid)
                    ops += d - mid;
            }

            if (ops <= k)
                high = mid;
            else
                low = mid + 1;
        }

        // Reduce all differences to at most low
        long long ans = 0;
        long long used = 0;

        for (int d : diff) {
            if (d > low) {
                used += d - low;
                d = low;
            }
            ans += 1LL * d * d;
        }

        // Distribute remaining operations:
        // each operation reduces one difference from low to low-1
        long long remaining = k - used;

        for (int i = 0; i < n && remaining > 0; i++) {
            if (diff[i] >= low && low > 0) {
                ans -= 2LL * low - 1;
                remaining--;
            }
        }

        return ans;
    }
};