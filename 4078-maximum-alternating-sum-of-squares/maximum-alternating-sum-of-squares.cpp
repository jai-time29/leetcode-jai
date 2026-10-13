#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        int n = nums.size();
        
        // Since max absolute value is 40,000, max square index is 40,000
        // We track the frequency of absolute values to save memory and operations
        std::vector<int> freq(40001, 0);
        for (int x : nums) {
            freq[std::abs(x)]++;
        }
        
        long long max_score = 0;
        int negative_count = n / 2; // Total number of elements we MUST subtract
        int items_processed = 0;
        
        // Traverse from smallest absolute values (0) to largest (40,000)
        for (long long val = 0; val <= 40000; ++val) {
            if (freq[val] == 0) continue;
            
            long long sq = val * val;
            int count = freq[val];
            
            // Determine how many of the current values fall into the "negative" partition
            if (items_processed < negative_count) {
                int take_negative = std::min(count, negative_count - items_processed);
                max_score -= (take_negative * sq);
                count -= take_negative;
                items_processed += take_negative;
            }
            
            // The remaining count naturally belongs to the "positive" partition
            if (count > 0) {
                max_score += (count * sq);
            }
        }
        
        return max_score;
    }
};

