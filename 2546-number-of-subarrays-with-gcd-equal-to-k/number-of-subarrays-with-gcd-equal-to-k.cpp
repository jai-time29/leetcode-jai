class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n=nums.size(),ans=0,tempgcd;
        for(int i=0;i<n;i++){
             tempgcd=0;
            for(int j=i;j<n;j++){
                tempgcd=gcd(tempgcd,nums[j]);
                if(tempgcd==k)ans++;
                else if(tempgcd<k)break;
                else if(tempgcd%k!=0)break;
            }
            
        }
        return ans;
    }
};