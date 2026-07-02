class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int prefix = 0;
        int mn = 0, mx = 0;

        for(int x : nums){
            prefix += x;
            mn = min(mn, prefix);
            mx = max(mx, prefix);
        }

        return mx - mn;
    }
};
/*
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int curMax = nums[0], maxSum = nums[0];
        int curMin = nums[0], minSum = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            // Normal Kadane
            curMax = max(nums[i], curMax + nums[i]);
            maxSum = max(maxSum, curMax);

            // Minimum Kadane
            curMin = min(nums[i], curMin + nums[i]);
            minSum = min(minSum, curMin);
        }

        return max(maxSum, -minSum);
    }
}; */