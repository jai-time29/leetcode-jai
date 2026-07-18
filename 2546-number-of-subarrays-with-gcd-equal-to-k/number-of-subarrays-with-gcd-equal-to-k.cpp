class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            int tempgcd=0;
            for(int j=i;j<n;j++){
                tempgcd=gcd(tempgcd,nums[j]);
                if(tempgcd==k)ans++;
            }
            
        }
        return ans;
    }
};