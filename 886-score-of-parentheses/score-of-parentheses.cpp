class Solution {
public:
    int solve(string& s, int start, int end) {
        if(start > end)
            return 0;

        // "()" 
        if(start + 1 == end)
            return 1;

        int balance = 0;

        // Find where the first balanced part ends
        for(int i = start; i <= end; i++) {
            if(s[i] == '(')
                balance++;
            else
                balance--;

            if(balance == 0) {
                // Whole string is (A)
                if(i == end) {
                    return 2 * solve(s, start + 1, end - 1);
                }

                // String is A + B
                return solve(s, start, i) + solve(s, i + 1, end);
            }
        }

        return 0;
    }

    int scoreOfParentheses(string s) {
        return solve(s, 0, s.size() - 1);
    }
};