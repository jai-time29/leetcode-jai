class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size(),j=0,k=0;
             for(int i=0;i<n;i++){
                if(i>0 && nums[i-1]==nums[i])continue;
                j=i+1;
                k=n-1;
             while(j<k){
                int sum =nums[i]+nums[j]+nums[k];

                if(sum<0)j++;
               else if(sum>0)k--;
            else {
                vector<int>temp = {nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[k+1]==nums[k])k--;
                while(j<k && nums[j]==nums[j-1])j++;
               
            }
  }
 }
             return ans;
    }
};