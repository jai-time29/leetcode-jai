class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>twosum;
        for(int i=0;i<nums.size();i++){
            if(twosum.find(target-nums[i])!= twosum.end()){
                ans.push_back(i);
                ans.push_back(twosum[target-nums[i]]);
            }
            else {
                twosum[nums[i]]=i;
            }
        }
        return ans;
    }
};