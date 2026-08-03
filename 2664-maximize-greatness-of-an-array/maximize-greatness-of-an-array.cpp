class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0;

        while (j < n) {
            if (nums[j] > nums[i]) {
                ans++;
                i++;
            }
            j++;
        }

        return ans;
    }
};