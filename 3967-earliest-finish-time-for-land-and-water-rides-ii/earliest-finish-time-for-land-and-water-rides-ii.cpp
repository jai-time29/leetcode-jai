class Solution {
public:

    long long getBest(vector<int>& startA, vector<int>& durA,
                      vector<int>& startB, vector<int>& durB) {

        int m = startB.size();

        vector<pair<int,int>> b(m);

        for(int i = 0; i < m; i++) {
            b[i] = {startB[i], durB[i]};
        }

        sort(b.begin(), b.end());

        vector<int> starts(m);
        vector<long long> pref(m), suff(m);

        for(int i = 0; i < m; i++) {
            starts[i] = b[i].first;
        }

        pref[0] = b[0].second;

        for(int i = 1; i < m; i++) {
            pref[i] = min(pref[i - 1], (long long)b[i].second);
        }

        suff[m - 1] = (long long)b[m - 1].first + b[m - 1].second;

        for(int i = m - 2; i >= 0; i--) {
            suff[i] = min(
                suff[i + 1],
                (long long)b[i].first + b[i].second
            );
        }

        long long ans = LLONG_MAX;

        for(int i = 0; i < startA.size(); i++) {

            long long finishA =
                (long long)startA[i] + durA[i];

            int pos = upper_bound(
                starts.begin(),
                starts.end(),
                finishA
            ) - starts.begin();

            if(pos)
                ans = min(ans,
                          finishA + pref[pos - 1]);

            if(pos < m)
                ans = min(ans,
                          suff[pos]);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        return (int)min(
            getBest(landStartTime, landDuration,
                    waterStartTime, waterDuration),

            getBest(waterStartTime, waterDuration,
                    landStartTime, landDuration)
        );
    }
};