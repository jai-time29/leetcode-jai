// class Solution {
// public:
//     int countHillValley(vector<int>& nums) {
//         int n = nums.size();
//         int ans = 0;

//         for (int i = 1; i < n - 1; i++) {

//             // skip duplicates on left
//             int l = i - 1;
//             while (l >= 0 && nums[l] == nums[i])
//                 l--;

//             // skip duplicates on right
//             int r = i + 1;
//             while (r < n && nums[r] == nums[i])
//                 r++;

//             // valid neighbors must exist
//             if (l >= 0 && r < n) {

//                 // hill
//                 if (nums[i] > nums[l] && nums[i] > nums[r])
//                     ans++;

//                 // valley
//                 else if (nums[i] < nums[l] && nums[i] < nums[r])
//                     ans++;
//             }
//         }

//         return ans;
//     }
// };




class Solution {
public:
    int countHillValley(vector<int>& nums) {

        vector<int> arr;

        // remove consecutive duplicates
        arr.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1])
                arr.push_back(nums[i]);
        }

        int ans = 0;

        for (int i = 1; i < arr.size() - 1; i++) {

            // hill
            if (arr[i] > arr[i - 1] &&
                arr[i] > arr[i + 1])
                ans++;

            // valley
            else if (arr[i] < arr[i - 1] &&
                     arr[i] < arr[i + 1])
                ans++;
        }

        return ans;
    }
}; 