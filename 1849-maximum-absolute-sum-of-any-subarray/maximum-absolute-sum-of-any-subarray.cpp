class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int prefix = 0;
        int mn = 0, mx = 0;

        for(int x : nums){
            prefix += x;
            mn = min(mn, prefix);
            mx = max(mx, prefix);
        }

        return mx - mn;
    }
};