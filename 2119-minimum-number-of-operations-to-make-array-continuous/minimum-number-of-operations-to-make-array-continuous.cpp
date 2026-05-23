class Solution {
public:

    int minOperations(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> arr;

        // remove duplicates
        for (int x : nums) {

            if (arr.empty() ||
                arr.back() != x) {

                arr.push_back(x);
            }
        }

        int left = 0;

        int maxWindow = 0;

        for (int right = 0;
             right < arr.size();
             right++) {

            while (arr[right] - arr[left] >= n) {

                left++;
            }

            maxWindow = max(
                maxWindow,
                right - left + 1
            );
        }

        return n - maxWindow;
    }
};