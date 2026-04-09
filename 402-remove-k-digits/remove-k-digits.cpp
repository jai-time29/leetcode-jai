class Solution {
public:
    string removeKdigits(string num, int k) {
        list<int> st;
        string ans;
        int count = 0;

        for (auto s : num) {
            int temp = s - '0';

            while (!st.empty() && st.back() > temp && count < k) {
                st.pop_back();
                count++;
            }
            st.push_back(temp);
        }

        // 🔥 FIX 1: remove remaining digits from back
        while (count < k && !st.empty()) {
            st.pop_back();
            count++;
        }

        // 🔥 remove leading zeros
        while (!st.empty() && st.front() == 0) {
            st.pop_front();
        }

        // build answer
        for (auto i : st) {
            ans += char('0' + i);
        }

        // 🔥 FIX 2: if empty, return "0"
        return ans.empty() ? "0" : ans;
    }
};