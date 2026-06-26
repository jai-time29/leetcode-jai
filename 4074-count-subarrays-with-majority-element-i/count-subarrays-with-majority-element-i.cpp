class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> pref(n+1,0);

        for(int i=0;i<n;i++){

            if(nums[i]==target)
                pref[i+1]=pref[i]+1;
            else
                pref[i+1]=pref[i]-1;
        }


        int ans=0;

        for(int i=0;i<n;i++){

            for(int j=i+1;j<=n;j++){

                if(pref[j]-pref[i]>0)
                    ans++;
            }
        }

        return ans;
    }
};