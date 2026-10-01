class Solution {
public:
    bool isValid(string s) {
                int n= s.length();
                stack<char>st;
                for(int i=0;i<n;i++){
                    if(s[i]==')' && !st.empty() && st.top()=='(')st.pop();
                    else if(s[i]==']' && !st.empty() && st.top()=='[')st.pop();
                    else if(s[i]=='}' && !st.empty() && st.top()=='{')st.pop();
                   else st.push(s[i]);
                }
                if(st.empty())return true;
           return false ;
    }
};