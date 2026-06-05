class Solution {
public:
    int gcd(int a, int b){
        while(b){
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    int firstDigit(int x){
        while(x >= 10) x /= 10;
        return x;
    }

    /*int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            int first = firstDigit(nums[i]);

            for(int j = i + 1; j < n; j++){
                int last = nums[j] % 10;

                if(gcd(first, last) == 1)
                    ans++;
            }
        }

        return ans;
    }
    */
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            while(first >= 10) first /= 10;

            for(int j = i + 1; j < nums.size(); j++) {
                if(__gcd(first, nums[j] % 10) == 1)
                    ans++;
            }
        }

        return ans;
    }
};
