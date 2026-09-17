class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<int> pref(n, INT_MAX);
        vector<int> suff(n, INT_MAX);

        unordered_map<long long, int> lastind;
        long long sum = 0;

        lastind[0] = -1;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (lastind.count(sum - target)) {
                pref[i] = i - lastind[sum - target];
            }

            lastind[sum] = i;
        }
         for (int i = 1; i < n; i++) {
            pref[i] = min(pref[i], pref[i - 1]);
        }
        unordered_map<long long, int> slastind;
        sum = 0;

        slastind[0] = n;

        for (int i = n - 1; i >= 0; i--) {
            sum += arr[i];

            if (slastind.count(sum - target)) {
                suff[i] = slastind[sum - target] - i;
            }

            slastind[sum] = i;
        }
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = min(suff[i], suff[i + 1]);
        }
        int mini = INT_MAX;

        for (int i = 1; i < n; i++) {
            if (pref[i-1] != INT_MAX && suff[i] != INT_MAX) {
                
                mini = min(mini, pref[i-1] + suff[i]);
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};