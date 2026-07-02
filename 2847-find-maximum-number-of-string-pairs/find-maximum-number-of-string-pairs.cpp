class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {

        int ans = 0;

        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {

                string rev = words[j];
                reverse(rev.begin(), rev.end());

                if (rev == words[i])
                    ans++;
            }
        }

        return ans;
    }
};