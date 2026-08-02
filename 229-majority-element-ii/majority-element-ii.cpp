class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int c1=nums[0],c2=nums[0],n=nums.size(),count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==c1)count1++;
          else  if(nums[i]==c2)count2++;
          else if(count1==0){
            c1 = nums[i];
            count1=1;
          }
          else if(count2 ==0){
            c2=nums[i];
            count2 = 1;
          }
          else {
            count1--;
            count2--;
          }

        }
       count1 = count2 = 0;
    for(int num : nums) {
        if(num == c1) count1++;
        else if(num == c2) count2++;
    }

    vector<int> result;
    if(count1 > n/3) result.push_back(c1);
    if(count2 > n/3) result.push_back(c2);

    return result;
    }
};