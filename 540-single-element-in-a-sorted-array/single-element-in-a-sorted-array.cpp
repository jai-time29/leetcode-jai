class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            // check pair alignment
            if (nums[mid] == nums[mid ^ 1]) {

                // single element on right
                low = mid + 1;
            }
            else {

                // single element on left
                high = mid;
            }
        }

        return nums[low];
    }
};