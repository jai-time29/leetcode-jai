class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return n;
        int mini=0,maxi=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[mini]>nums[i])mini=i;
            if(nums[maxi]<nums[i])maxi=i;

        }
       int a=min(maxi,mini);
       int b=max(maxi,mini);
        return min({n-a,b+1,n-b+a+1});
       
    }
};