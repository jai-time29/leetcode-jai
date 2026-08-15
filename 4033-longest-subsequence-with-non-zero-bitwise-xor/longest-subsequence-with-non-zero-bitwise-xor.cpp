class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool nonZero = false;

        for(int x : nums) {
            xr ^= x;

            if(x != 0)
                nonZero = true;
        }

        // Entire array itself has non-zero XOR
        if(xr != 0)
            return n;

        // Entire XOR is zero, but removing one non-zero
        // element makes the remaining XOR non-zero
        if(nonZero)
            return n - 1;

        // All elements are zero
        return 0;
    }
};