/*class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        int n = nums.size();

        int left = (n - 1) / 2;   // end of first half
        int right = n - 1;        // end of second half

        for (int i = 0; i < n; i++) {

            if (i % 2 == 0)
                nums[i] = temp[left--];
            else
                nums[i] = temp[right--];
        }
    }
};*/

class Solution {
public:
    int virtualIndex(int i, int n) {
        return (1 + 2 * i) % (n | 1);
    }

    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        // Find median
        auto mid = nums.begin() + n / 2;
        nth_element(nums.begin(), mid, nums.end());
        int median = *mid;

        int left = 0;
        int i = 0;
        int right = n - 1;

        while (i <= right) {

            int vi = virtualIndex(i, n);

            if (nums[vi] > median) {
                swap(nums[virtualIndex(left, n)], nums[vi]);
                left++;
                i++;
            }
            else if (nums[vi] < median) {
                swap(nums[virtualIndex(right, n)], nums[vi]);
                right--;
            }
            else {
                i++;
            }
        }
    }
};