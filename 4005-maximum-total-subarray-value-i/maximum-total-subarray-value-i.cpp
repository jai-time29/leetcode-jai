class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini=nums[0],maxi=nums[0];
        for(int i=0;i<nums.size();i++){
            mini= min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        long long ans = (maxi-mini);
        return ans*k;
    }
};