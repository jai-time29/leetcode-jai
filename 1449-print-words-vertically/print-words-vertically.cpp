class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        string temp;

        // split words
        for (char c : s) {
            if (c == ' ') {
                words.push_back(temp);
                temp.clear();
            }
            else {
                temp += c;
            }
        }
        words.push_back(temp);

        int mx = 0;

        for (auto &word : words)
            mx = max(mx, (int)word.size());

        vector<string> ans;

        for (int i = 0; i < mx; i++) {
            string row = "";

            for (auto &word : words) {
                if (i < word.size())
                    row += word[i];
                else
                    row += ' ';
            }

            // remove trailing spaces
            while (!row.empty() && row.back() == ' ')
                row.pop_back();

            ans.push_back(row);
        }

        return ans;
    }
};