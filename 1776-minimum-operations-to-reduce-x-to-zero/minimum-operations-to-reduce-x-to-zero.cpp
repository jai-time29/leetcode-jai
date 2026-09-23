class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;

        for(int num : nums)
            sum += num;

        int target = sum - x;

        if(target < 0)
            return -1;

        if(target == 0)
            return n;

        unordered_map<int,int> mp;
        mp[0] = -1;

        int pref = 0;
        int ans = -1;

        for(int i = 0; i < n; i++) {
            pref += nums[i];

            if(mp.count(pref - target)) {
                ans = max(ans, i - mp[pref - target]);
            }

            mp[pref] = i;
        }

        if(ans == -1)
            return -1;

        return n - ans;
    }
};