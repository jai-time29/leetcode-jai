class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
    
        vector<int>prefixmax(n,0),suffixmin(n,INT_MAX);
        int mini=nums[n-1],maxi=nums[0];
        for(int i=0;i<n;i++){
              prefixmax[i]=max(maxi,nums[i]);
              suffixmin[n-i-1]=min(mini,nums[n-i-1]);
             mini=min(mini,nums[n-i-1]);
             maxi=max(maxi,nums[i]);

        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(prefixmax[i]-suffixmin[i]<=k){ans=i;break;}
        }
        return ans;
    }
};