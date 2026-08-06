class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(),maxi=nums[0],mini=nums[0],ans=nums[0];
       for(int i=1;i<n;i++) {
        int curr = nums[i];
        int tempmin = min({curr,curr*maxi,curr*mini});
        int tempmax = max({curr,curr*maxi,curr*mini});
        maxi = tempmax;
        mini = tempmin;
        ans= max(maxi,ans);
       }
       return ans;
    }
};