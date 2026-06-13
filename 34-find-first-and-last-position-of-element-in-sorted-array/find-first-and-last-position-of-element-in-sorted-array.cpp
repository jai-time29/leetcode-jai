class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();

        int first = -1;
        int low = 0, high = n - 1;

        // find first occurrence
        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                first = mid;
                high = mid - 1;   // search left side
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }


        int last = -1;
        low = 0;
        high = n - 1;

        // find last occurrence
        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                last = mid;
                low = mid + 1;    // search right side
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return {first, last};
    }
};