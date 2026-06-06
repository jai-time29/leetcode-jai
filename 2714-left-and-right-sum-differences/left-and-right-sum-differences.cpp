class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int rightsum[n];
        int curr=0;
        for(int i=n-1;i>=0;i--){
            rightsum[i]=curr;
           curr+= nums[i];
        }
        vector<int>ans;
        curr=0;
        int diff=0;
        for(int i=0;i<n;i++){
            diff = rightsum[i]-curr;
            ans.push_back(abs(diff));
            curr+=nums[i];
        }
        return ans;
    }
};