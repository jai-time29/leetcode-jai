class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
       unordered_set<int> hashing(nums.begin(), nums.end());
        
        int sum=nums[0];
        for(int i=1;i<n;i++){
            
            if(nums[i]==nums[i-1]+1){sum+=nums[i];}
            else break;
        }
        
        while(hashing.count(sum))sum++;
        return sum;
    }
};