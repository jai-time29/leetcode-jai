class Solution {
public:
    long long waviness(long long x) {

        string s = to_string(x);

        if (s.size() < 3)
            return 0;

        long long cnt = 0;

        for (int i = 1; i < (int)s.size() - 1; i++) {

            if (s[i] > s[i - 1] && s[i] > s[i + 1])
                cnt++;

            else if (s[i] < s[i - 1] && s[i] < s[i + 1])
                cnt++;
        }

        return cnt;
    }

    long long totalWaviness(int num1, int num2) {

        long long ans = 0;

        for (int x = num1; x <= num2; x++) {
            ans += waviness(x);
        }

        return ans;
    }
};