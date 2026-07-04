class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size(), m = num2.size();

        vector<int> ans(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                int mul = (num1[i] - '0') * (num2[j] - '0');

                int pos2 = i + j + 1;
                int pos1 = i + j;

                int sum = mul + ans[pos2];

                ans[pos2] = sum % 10;
                ans[pos1] += sum / 10;
            }
        }

        string res;

        int i = 0;
        while (i < ans.size() && ans[i] == 0)
            i++;

        while (i < ans.size())
            res += char(ans[i++] + '0');

        return res;
    }
};