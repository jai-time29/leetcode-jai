class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (is_sorted(s.begin(), s.end())) return 0;
        if(s.size()==2 && s[0]>s[1])return -1;
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if (s[0] == mn || s[n-1] == mx) return 1;

        bool prefix = false, suffix = false;

        for (int i = 0; i < n-1; i++)
            if (s[i] == mn) prefix = true;

        for (int i = 1; i < n; i++)
            if (s[i] == mx) suffix = true;

        if (!prefix && !suffix) return 3;
        return 2;
    }
};

