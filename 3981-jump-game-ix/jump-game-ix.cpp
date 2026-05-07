class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        int maxPrefix[n];
        int minSuffix[n];
        maxPrefix[0]=nums[0];
        minSuffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++)maxPrefix[i]=max(maxPrefix[i-1],nums[i]);
        for(int i=n-2;i>=0;i--)minSuffix[i]=min(minSuffix[i+1],nums[i]);
        vector<int>ans(n,0);
        ans[n-1]=maxPrefix[n-1];
        for(int i=n-2;i>=0;i--){
             if(maxPrefix[i]>minSuffix[i+1]){
                ans[i]=ans[i+1];
             }
             else ans[i]=maxPrefix[i];
        }
        return ans;
    }
};