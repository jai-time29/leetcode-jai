class Solution {
public:

    int solve(vector<int>& nums, int l, int r) {

        if (l == r)
            return nums[l];

        int mid = l + (r - l) / 2;

        int leftAns = solve(nums, l, mid);
        int rightAns = solve(nums, mid + 1, r);

        int leftSum = INT_MIN;
        int sum = 0;

        for (int i = mid; i >= l; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        int rightSum = INT_MIN;
        sum = 0;

        for (int i = mid + 1; i <= r; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

        int cross = leftSum + rightSum;

        return max({leftAns, rightAns, cross});
    }

    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};