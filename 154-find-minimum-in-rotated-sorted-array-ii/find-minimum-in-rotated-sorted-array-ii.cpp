class Solution {
public:

    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {

            int mid =
                low + (high - low) / 2;

            // minimum in right half
            if (nums[mid] > nums[high]) {

                low = mid + 1;
            }

            // minimum in left half including mid
            else if (nums[mid] < nums[high]) {

                high = mid;
            }

            // duplicates: cannot decide
            else {

                high--;
            }
        }

        return nums[low];
    }
};