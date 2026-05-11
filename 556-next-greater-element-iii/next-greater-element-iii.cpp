class Solution {
public:
    int nextGreaterElement(int n) {

        string s = to_string(n);

        int i = s.size() - 2;

        // Find pivot
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }

        if (i < 0) return -1;

        // Find next greater digit
        int j = s.size() - 1;

        while (s[j] <= s[i]) {
            j--;
        }

        swap(s[i], s[j]);

        // Make suffix smallest
        reverse(s.begin() + i + 1, s.end());

        long long ans = stoll(s);

        return (ans > INT_MAX) ? -1 : ans;
    }
};