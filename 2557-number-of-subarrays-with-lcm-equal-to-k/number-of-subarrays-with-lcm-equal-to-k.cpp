// class Solution {
// public:
//     int subarrayLCM(vector<int>& nums, int k) {
//         int n=nums.size(),ans=0;
//         long long tempgcd;
//         for(int i=0;i<n;i++){
//              tempgcd=1;
//             for(int j=i;j<n;j++){
//                 tempgcd=(tempgcd/gcd(tempgcd,1LL*nums[j]))*nums[j];
//                 if(tempgcd==k)ans++;
//                 // else if(tempgcd<k)break;
//                 // else if(tempgcd%k!=0)break;
//             }
            
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
long long l=1;
        for (int i = 0; i < n; i++) {
            l = 1;

            for (int j = i; j < n; j++) {
                l = (l / gcd(l, 1LL * nums[j])) * nums[j];

                if (l == k)
                    ans++;
                else if (l > k)
                    break;
                else if (k % l != 0)
                    break;
            }
        }

        return ans;
    }
};