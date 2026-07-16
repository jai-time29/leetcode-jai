class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>gcdofnum;
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
              gcdofnum.push_back(gcd(maxi,nums[i]));
        }
        long long ans=0;
        sort(gcdofnum.begin(), gcdofnum.end());
        for(int i=0;i<n/2;i++){
         ans+=gcd(gcdofnum[i],gcdofnum[n-i-1]);
        }
        
        return ans;
    }
};