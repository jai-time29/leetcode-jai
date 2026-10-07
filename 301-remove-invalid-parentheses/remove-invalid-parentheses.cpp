class Solution {
public:
    unordered_set<string> st;

    void dfs(string& s, int i, int leftRem, int rightRem,
             int balance, string& path) {

        if (i == s.size()) {
            if (leftRem == 0 && rightRem == 0 && balance == 0) {
                st.insert(path);
            }
            return;
        }

        char c = s[i];

        // Remove current '('
        if (c == '(' && leftRem > 0) {
            dfs(s, i + 1, leftRem - 1, rightRem,
                balance, path);
        }

        // Remove current ')'
        if (c == ')' && rightRem > 0) {
            dfs(s, i + 1, leftRem, rightRem - 1,
                balance, path);
        }

        // Keep current character
        if (c == '(') {
            path.push_back(c);

            dfs(s, i + 1, leftRem, rightRem,
                balance + 1, path);

            path.pop_back();
        }
        else if (c == ')') {
            // Can't keep ')' without an unmatched '('
            if (balance > 0) {
                path.push_back(c);

                dfs(s, i + 1, leftRem, rightRem,
                    balance - 1, path);

                path.pop_back();
            }
        }
        else {
            // Letter
            path.push_back(c);

            dfs(s, i + 1, leftRem, rightRem,
                balance, path);

            path.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        st.clear();

        int leftRem = 0;
        int rightRem = 0;

        // Calculate minimum removals
        for (char c : s) {
            if (c == '(') {
                leftRem++;
            }
            else if (c == ')') {
                if (leftRem > 0)
                    leftRem--;
                else
                    rightRem++;
            }
        }

        string path;

        dfs(s, 0, leftRem, rightRem, 0, path);

        return vector<string>(st.begin(), st.end());
    }
};