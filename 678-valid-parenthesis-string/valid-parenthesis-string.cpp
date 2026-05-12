class Solution {
public:
    bool checkValidString(string s) {

        int low = 0;
        int high = 0;

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }

            else if (ch == ')') {
                low--;
                high--;
            }

            else { // '*'
                low--;
                high++;
            }

            // minimum open brackets can't go below 0
            low = max(low, 0);

            // too many closing brackets
            if (high < 0)
                return false;
        }

        return low == 0;
    }
};