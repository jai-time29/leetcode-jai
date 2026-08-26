class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size(), l = 0, cnt = 0, minlen = INT_MAX;
        string ans = "";

        for (int r = 0; r < n; r++) {
            if (s[r] == '1') cnt++;

            while (cnt > k) {
                if (s[l] == '1') cnt--;
                l++;
            }

            if (cnt == k) {
                while (s[l] == '0') l++;

                string cur = s.substr(l, r - l + 1);

                if (cur.size() < minlen ||
                    (cur.size() == minlen && (ans.empty() || cur < ans))) {
                    minlen = cur.size();
                    ans = cur;
                }
            }
        }

        return ans;
    }
};