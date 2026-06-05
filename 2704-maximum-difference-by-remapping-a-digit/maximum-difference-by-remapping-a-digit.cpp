class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        char mxDigit = 0;
        char mnDigit = s[0];

        // One iteration to find the digits to remap
        for(char c : s) {
            if(mxDigit == 0 && c != '9')
                mxDigit = c;
        }

        string mx = s, mn = s;

        // One iteration to perform both remaps
        for(int i = 0; i < s.size(); i++) {
            if(mxDigit && s[i] == mxDigit)
                mx[i] = '9';

            if(s[i] == mnDigit)
                mn[i] = '0';
        }

        return stoi(mx) - stoi(mn);
    }
};