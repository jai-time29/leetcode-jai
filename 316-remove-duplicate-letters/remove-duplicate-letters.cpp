class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();

        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        vector<int> vis(26, 0);
        stack<char> st;

        for (char c : s) {
            freq[c - 'a']--;

            if (vis[c - 'a'])
                continue;

            while (!st.empty() &&
                   st.top() > c &&
                   freq[st.top() - 'a'] > 0) {
                vis[st.top() - 'a'] = 0;
                st.pop();
            }

            st.push(c);
            vis[c - 'a'] = 1;
        }

        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};