class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
    long long pro = 1;
    long long target =1;
        for (int i = 0; i < n; i++) {
            pro = 1;
            long long l = 1;
            long long g = 0;
            
            for (int j = i; j < n; j++) {
               
                 
                 
                  
                g = std::gcd(g, nums[j]);
                l = std::lcm(l, (long long)nums[j]);
                
                target=l*g;

                if (pro > target / nums[j])
                    break;
                 pro *= nums[j];
                if (pro == l * g) {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }

        return maxi;
    }
};