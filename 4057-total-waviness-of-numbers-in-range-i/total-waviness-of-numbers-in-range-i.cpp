class Solution {
public:
    int d[10];

int waviness(int x) {

    int len = 0;

    while (x) {
        d[len++] = x % 10;
        x /= 10;
    }

    if (len < 3)
        return 0;

    int cnt = 0;

    for (int i = len - 2; i >= 1; i--) {

        if ((d[i] > d[i - 1] && d[i] > d[i + 1]) ||
            (d[i] < d[i - 1] && d[i] < d[i + 1]))
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
