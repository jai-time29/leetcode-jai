class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallestOdd = INT_MAX;

        // Find smallest odd number
        for (int x : nums1) {
            if (x & 1)
                smallestOdd = min(smallestOdd, x);
        }

        // If all are already even, all-even is possible
        if (smallestOdd == INT_MAX)
            return true;

        // Try making everything odd.
        // Every even x needs x - odd > 0.
        for (int x : nums1) {
            if (!(x & 1) && x <= smallestOdd)
                return false;
        }

        return true;
    }
};