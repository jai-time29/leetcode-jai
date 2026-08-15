class Solution {
public:

    bool check(vector<int>& nums, int k, long long cap) {
        int count = 0;
        int n = nums.size();

        for(int i = 0; i < n; ) {

            if(nums[i] <= cap) {
                count++;
                i += 2;       // cannot take adjacent house
            }
            else {
                i++;
            }

            if(count >= k)
                return true;
        }

        return false;
    }

    int minCapability(vector<int>& nums, int k) {

        long long lo = *min_element(nums.begin(), nums.end());
        long long hi = *max_element(nums.begin(), nums.end());

        while(lo < hi) {

            long long mid = lo + (hi - lo) / 2;

            if(check(nums, k, mid))
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};