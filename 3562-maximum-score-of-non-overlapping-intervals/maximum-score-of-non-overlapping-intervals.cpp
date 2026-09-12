class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> ids;
    };

    State better(State a, State b) {
        if (a.score != b.score)
            return a.score > b.score ? a : b;

        return a.ids < b.ids ? a : b; // lexicographically smaller
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Store original index
        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);

        // Sort by right endpoint
        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) {
                 return a[1] < b[1];
             });

        // j[i] = largest index whose right < current left
        vector<int> j(n);
        for (int i = 0; i < n; i++) {
            int l = intervals[i][0];

            int lo = 0, hi = i - 1;
            j[i] = -1;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (intervals[mid][1] < l) {
                    j[i] = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }

        // dp[r][i] = best state using at most r intervals
        // from indices 0...i
        vector<vector<State>> dp(5, vector<State>(n));

        for (int i = 0; i < n; i++) {
            for (int r = 1; r <= 4; r++) {

                // Don't take i
                State skip = (i > 0 ? dp[r][i - 1] : State());

                // Take i
                State take;
                take.score = intervals[i][2];

                if (j[i] != -1)
                    take.score += dp[r - 1][j[i]].score;

                take.ids = (j[i] != -1 ? dp[r - 1][j[i]].ids
                                       : vector<int>{});

                take.ids.push_back(intervals[i][3]);
                sort(take.ids.begin(), take.ids.end());
                dp[r][i] = better(skip, take);
            }
        }
        //sort(dp[4][n - 1].ids.begin(),dp[4][n-1].ids.end());
        return dp[4][n - 1].ids;
    }
};