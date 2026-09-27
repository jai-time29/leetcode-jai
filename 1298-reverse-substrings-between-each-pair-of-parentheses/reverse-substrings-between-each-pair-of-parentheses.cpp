class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for(char c : s) {
            if(c != ')') {
                st.push(c);
            }
            else {
                string cur;

                while(st.top() != '(') {
                    cur += st.top();
                    st.pop();
                }

                st.pop(); // remove '('

                for(char x : cur)
                    st.push(x);
            }
        }

        string ans;

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};