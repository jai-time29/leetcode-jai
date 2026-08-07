class Solution {
public:
    const int INF = 1e9;

    int req2, req3, req5, req7;

    int D2, D3, D5, D7;
    vector<int> memo;

    // digit -> {power of 2, power of 3, power of 5, power of 7}
    int factor[10][4] = {
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 0}, // 1
        {1, 0, 0, 0}, // 2
        {0, 1, 0, 0}, // 3
        {2, 0, 0, 0}, // 4
        {0, 0, 1, 0}, // 5
        {1, 1, 0, 0}, // 6
        {0, 0, 0, 1}, // 7
        {3, 0, 0, 0}, // 8
        {0, 2, 0, 0}  // 9
    };

    int getId(int a, int b, int c, int d) {
        return (((a * D3 + b) * D5 + c) * D7 + d);
    }

    // Minimum number of digits needed to satisfy
    // remaining powers of 2,3,5,7.
    int dp(int a, int b, int c, int d) {

        if (a == 0 && b == 0 && c == 0 && d == 0)
            return 0;

        int idx = getId(a, b, c, d);

        if (memo[idx] != -1)
            return memo[idx];

        int ans = INF;

        for (int digit = 2; digit <= 9; digit++) {

            int na = max(0, a - factor[digit][0]);
            int nb = max(0, b - factor[digit][1]);
            int nc = max(0, c - factor[digit][2]);
            int nd = max(0, d - factor[digit][3]);

            // Prevent self-loop
            if (na == a && nb == b &&
                nc == c && nd == d) {
                continue;
            }

            int nxt = dp(na, nb, nc, nd);

            if (nxt != INF)
                ans = min(ans, 1 + nxt);
        }

        return memo[idx] = ans;
    }

    bool factorize(long long t) {

        req2 = req3 = req5 = req7 = 0;

        while (t % 2 == 0) {
            req2++;
            t /= 2;
        }

        while (t % 3 == 0) {
            req3++;
            t /= 3;
        }

        while (t % 5 == 0) {
            req5++;
            t /= 5;
        }

        while (t % 7 == 0) {
            req7++;
            t /= 7;
        }

        // Any remaining prime cannot be produced
        // by digits 1..9.
        return t == 1;
    }

    string buildSmallest(
        int len,
        int a,
        int b,
        int c,
        int d
    ) {

        string ans;

        for (int pos = 0; pos < len; pos++) {

            int remaining = len - pos - 1;

            for (int digit = 1; digit <= 9; digit++) {

                int na = max(0, a - factor[digit][0]);
                int nb = max(0, b - factor[digit][1]);
                int nc = max(0, c - factor[digit][2]);
                int nd = max(0, d - factor[digit][3]);

                if (dp(na, nb, nc, nd) <= remaining) {

                    ans.push_back('0' + digit);

                    a = na;
                    b = nb;
                    c = nc;
                    d = nd;

                    break;
                }
            }
        }

        return ans;
    }

    string smallestNumber(string num, long long t) {

        // -----------------------------------
        // 1. Factorize t
        // -----------------------------------

        if (!factorize(t))
            return "-1";

        // -----------------------------------
        // 2. DP dimensions
        // -----------------------------------

        D2 = req2 + 1;
        D3 = req3 + 1;
        D5 = req5 + 1;
        D7 = req7 + 1;

        memo.assign(D2 * D3 * D5 * D7, -1);

        int n = num.size();

        // -----------------------------------
        // 3. Prefix requirements
        // -----------------------------------

        vector<array<int, 4>> pref(n + 1);

        pref[0] = {
            req2,
            req3,
            req5,
            req7
        };

        bool zeroFound = false;

        for (int i = 0; i < n; i++) {

            int digit = num[i] - '0';

            if (digit == 0) {
                zeroFound = true;
                break;
            }

            pref[i + 1] = pref[i];

            pref[i + 1][0] =
                max(0, pref[i + 1][0] - factor[digit][0]);

            pref[i + 1][1] =
                max(0, pref[i + 1][1] - factor[digit][1]);

            pref[i + 1][2] =
                max(0, pref[i + 1][2] - factor[digit][2]);

            pref[i + 1][3] =
                max(0, pref[i + 1][3] - factor[digit][3]);
        }

        // -----------------------------------
        // 4. num itself
        // -----------------------------------

        if (!zeroFound) {

            auto &r = pref[n];

            if (r[0] == 0 &&
                r[1] == 0 &&
                r[2] == 0 &&
                r[3] == 0) {

                return num;
            }
        }

        // -----------------------------------
        // 5. Find same-length answer
        // -----------------------------------

        int bestPos = -1;
        int bestDigit = -1;

        /*
            We try the RIGHTMOST position where we
            can make the number larger.

            Example:

                num = 19
                t = 2

            position 1:
                9 -> nothing larger

            position 0:
                1 -> 2

            suffix:
                1

            answer = 21
        */


vector<bool> prefixZero(n + 1, false);

for (int i = 0; i < n; i++) {
    prefixZero[i + 1] = prefixZero[i] || (num[i] == '0');
}

for (int pos = n - 1; pos >= 0; pos--) {

    if (prefixZero[pos])
        continue;

    int a = pref[pos][0];
    int b = pref[pos][1];
    int c = pref[pos][2];
    int d = pref[pos][3];

    int original = num[pos] - '0';

    for (int digit = original + 1;
         digit <= 9;
         digit++) {

        int na = max(0, a - factor[digit][0]);
        int nb = max(0, b - factor[digit][1]);
        int nc = max(0, c - factor[digit][2]);
        int nd = max(0, d - factor[digit][3]);

        int remaining = n - pos - 1;

        if (dp(na, nb, nc, nd) <= remaining) {

            bestPos = pos;
            bestDigit = digit;

            break;
        }
    }

    if (bestPos != -1)
        break;
}

        // -----------------------------------
        // 6. Construct same-length answer
        // -----------------------------------

        if (bestPos != -1) {

            string ans = num.substr(0, bestPos);

            ans.push_back('0' + bestDigit);

            int a = pref[bestPos][0];
            int b = pref[bestPos][1];
            int c = pref[bestPos][2];
            int d = pref[bestPos][3];

            a = max(
                0,
                a - factor[bestDigit][0]
            );

            b = max(
                0,
                b - factor[bestDigit][1]
            );

            c = max(
                0,
                c - factor[bestDigit][2]
            );

            d = max(
                0,
                d - factor[bestDigit][3]
            );

            ans += buildSmallest(
                n - bestPos - 1,
                a,
                b,
                c,
                d
            );

            return ans;
        }

        // -----------------------------------
        // 7. Need a longer number
        // -----------------------------------

        int minLen = dp(
            req2,
            req3,
            req5,
            req7
        );

        int len = max(n + 1, minLen);
        
       
        return buildSmallest(
            len,
            req2,
            req3,
            req5,
            req7
        );
    }
};