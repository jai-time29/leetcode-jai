class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> nums;
        int fact = 1;

        for (int i = 1; i < n; i++) {
            fact *= i;
            nums.push_back(i);
        }

        nums.push_back(n);

        k--; // convert to 0-based

        string ans = "";

        while (true) {

            int index = k / fact;

            ans += to_string(nums[index]);

            nums.erase(nums.begin() + index);

            if (nums.size() == 0)
                break;

            k %= fact;

            fact /= nums.size();
        }

        return ans;
    }
};