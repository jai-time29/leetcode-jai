class Solution {
public:
    vector<string> ones = {
        "", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen",
        "Nineteen"
    };

    vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty",
        "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string helper(int n) {
        string res;

        if (n >= 100) {
            res += ones[n / 100] + " Hundred";
            n %= 100;
            if (n) res += " ";
        }

        if (n >= 20) {
            res += tens[n / 10];
            n %= 10;
            if (n) res += " ";
        }

        if (n > 0)
            res += ones[n];

        return res;
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        vector<string> units = {"", "Thousand", "Million", "Billion"};
        string ans;
        int i = 0;

        while (num > 0) {
            int chunk = num % 1000;

            if (chunk) {
                string cur = helper(chunk);

                if (!units[i].empty())
                    cur += " " + units[i];

                if (ans.empty())
                    ans = cur;
                else
                    ans = cur + " " + ans;
            }

            num /= 1000;
            i++;
        }

        return ans;
    }
};