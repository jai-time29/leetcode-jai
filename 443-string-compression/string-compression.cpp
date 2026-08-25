class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int l = 0, ans = 0;

        while (l < n) {

            int r = l;

            // find end of current group
            while (r < n && chars[r] == chars[l])
                r++;

            int cnt = r - l;

            // write character
            chars[ans++] = chars[l];

            // write count if > 1
            if (cnt > 1) {
                string num = to_string(cnt);

                for (char c : num)
                    chars[ans++] = c;
            }

            l = r;
        }

        return ans;
    }
};