#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<long long> squares(n);
        
        // 1. Calculate the squares of all elements
        for (int i = 0; i < n; ++i) {
            squares[i] = static_cast<long long>(nums[i]) * nums[i];
        }
        
        // 2. Sort squares in ascending order
        std::sort(squares.begin(), squares.end());
        
        long long max_score = 0;
        int negative_count = n / 2; // Number of elements at odd indices (subtracted)
        
        // 3. Subtract the smallest squares
        for (int i = 0; i < negative_count; ++i) {
            max_score -= squares[i];
        }
        
        // 4. Add the largest squares
        for (int i = negative_count; i < n; ++i) {
            max_score += squares[i];
        }
        
        return max_score;
    }
};
