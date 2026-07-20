class Solution {
    
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,0);
        int mx=INT_MIN;
        dp[n]=0;
        

        for (int i = n - 1; i >= 0; i--) {
          mx=0;
            int best = 0;

            for (int j = i; j < min(n, i + k); j++) {
                mx = max(mx, arr[j]);
                best = max(best, mx * (j - i + 1) + dp[j + 1]);
            }

            dp[i] = best;
        }
    

        return dp[0];
    }
};