class Solution {
public:
    int minSwaps(string s) {
        int balance = 0, mn = 0;

        for (char c : s) {
            if (c == '[')
                balance++;
            else
                balance--;

            mn = min(mn, balance);
        }

        return (-mn + 1) / 2;
    }
};