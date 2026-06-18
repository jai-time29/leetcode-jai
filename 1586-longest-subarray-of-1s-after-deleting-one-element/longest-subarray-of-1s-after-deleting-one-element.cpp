class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int zeros = 0;
        int ans = 0;

        for(int r = 0; r < n; r++) {

            if(nums[r] == 0)
                zeros++;

            // shrink window if we have more than one zero
            while(zeros > 1) {
                if(nums[l] == 0)
                    zeros--;
                l++;
            }

            // delete one element from the window
            ans = max(ans, r - l); 
        }

        return ans;
    }
};