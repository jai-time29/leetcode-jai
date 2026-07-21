class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int dipindex=-1,n=nums.size();
        for(int i= n-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                dipindex=i;
                break;
            }
        }
            if(dipindex==-1)reverse(nums.begin(),nums.end());
     else  if(dipindex!=-1){  int point = nums[dipindex];
            for(int i=n-1;i>=dipindex;i--){
                if(nums[i]>point){
                    nums[dipindex]=nums[i];
                    nums[i]=point;
                    break;
                }

            }
             reverse(nums.begin()+dipindex+1,nums.end());
       }
            
       
        
    }
};