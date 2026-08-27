class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        string ans;
        int n = s.size();

        // Try to build target as a prefix
        for (int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            // Can we place target[i]?
            if (cnt[x]) {
                cnt[x]--;
                ans += target[i];
                continue;
            }

            // Cannot match target[i]:
            // choose smallest character > target[i]
            for (int c = x + 1; c < 26; c++) {
                if (cnt[c]) {
                    ans += char('a' + c);
                    cnt[c]--;

                    for (int j = 0; j < 26; j++)
                        while (cnt[j]--)
                            ans += char('a' + j);

                    return ans;
                }
            }

            // No greater character -> need to backtrack
            break;
        }

        // We matched some prefix. Backtrack to find
        // the rightmost position that can be increased.
        for (int i = ans.size() - 1; i >= 0; i--) {

            cnt[ans[i] - 'a']++;

            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (cnt[c]) {
                    string res = target.substr(0, i);
                    res += char('a' + c);
                    cnt[c]--;

                    for (int j = 0; j < 26; j++)
                        while (cnt[j]--)
                            res += char('a' + j);

                    return res;
                }
            }
        }

        return "";
    }
};