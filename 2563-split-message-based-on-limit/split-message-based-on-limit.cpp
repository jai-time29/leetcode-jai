class Solution {
    bool can(int parts, string &s, int limit, int d) {
        long long cap = 0;

        for (int x = 1; x <= parts; ) {
            int digits = to_string(x).size();

            int last = min(parts, (int)pow(10, digits) - 1);

            if (digits > d) return false;

            int cnt = last - x + 1;
            int space = limit - digits - d - 3;

            if (space <= 0) return false;

            cap += 1LL * cnt * space;
            x = last + 1;
        }

        return cap >= s.size();
    }

public:
    vector<string> splitMessage(string message, int limit) {
        int n = message.size();

        for (int d = 1; d <= 5; d++) {

            int lo = 1, hi = n, parts = -1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                // parts must have exactly d digits
                if (to_string(mid).size() != d) {
                    if (to_string(mid).size() < d)
                        lo = mid + 1;
                    else
                        hi = mid - 1;
                    continue;
                }

                if (can(mid, message, limit, d)) {
                    parts = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            if (parts == -1) continue;

            vector<string> ans;
            int pos = 0;

            for (int i = 1; i <= parts; i++) {
                string suf = "<" + to_string(i) + "/" +
                             to_string(parts) + ">";

                int take = limit - suf.size();

                if (take <= 0) {
                    ans.clear();
                    break;
                }

                take = min(take, n - pos);
                ans.push_back(message.substr(pos, take) + suf);
                pos += take;
            }

            if (pos == n)
                return ans;
        }

        return {};
    }
};