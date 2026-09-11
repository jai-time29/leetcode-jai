class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for (int d : digits)
            freq[d]++;

        int ans = 0;

        for (int h = 1; h <= 9; h++) {          // hundreds
            if (freq[h] == 0) continue;
            freq[h]--;

            for (int t = 0; t <= 9; t++) {      // tens
                if (freq[t] == 0) continue;
                freq[t]--;

                for (int u = 0; u <= 8; u += 2) { // units: even
                    if (freq[u] == 0) continue;

                    ans++;
                }

                freq[t]++;
            }

            freq[h]++;
        }

        return ans;
    }
};