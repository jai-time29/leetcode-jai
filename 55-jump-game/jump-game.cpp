class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool ans=false;
        int maxIndex=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>maxIndex )break;
            maxIndex=max(maxIndex,i+nums[i]);
            
            if(maxIndex>=n-1){
                ans=true;
                break;
            } 
        }
        return ans;
    }
};