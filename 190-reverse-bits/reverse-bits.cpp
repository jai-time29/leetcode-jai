class Solution {
public:

    uint32_t reverseBits(uint32_t n) {

        uint32_t ans = 0;

        for(int i = 0; i < 32; i++) {

            // Shift ans left
            ans <<= 1;

            // Add last bit of n
            ans |= (n & 1);

            // Move to next bit
            n >>= 1;
        }

        return ans;
    }
};