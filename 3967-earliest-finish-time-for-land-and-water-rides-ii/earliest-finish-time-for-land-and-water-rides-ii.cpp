class Solution {
public:
    struct Ride {
        int start;
        int dur;
    };

    long long evaluate(
        const vector<int>& firstStart,
        const vector<int>& firstDur,
        const vector<int>& secondStarts,
        const vector<int>& prefMinDur,
        const vector<int>& suffMinFinish) {

        long long ans = LLONG_MAX;
        int m = secondStarts.size();

        for (int i = 0; i < firstStart.size(); i++) {

            long long finish = (long long)firstStart[i] + firstDur[i];

            int pos = upper_bound(
                secondStarts.begin(),
                secondStarts.end(),
                finish
            ) - secondStarts.begin();

            if (pos > 0) {
                ans = min(
                    ans,
                    finish + (long long)prefMinDur[pos - 1]
                );
            }

            if (pos < m) {
                ans = min(
                    ans,
                    (long long)suffMinFinish[pos]
                );
            }
        }

        return ans;
    }

    int earliestFinishTime(
        vector<int>& landStartTime,
        vector<int>& landDuration,
        vector<int>& waterStartTime,
        vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<Ride> land(n), water(m);

        for (int i = 0; i < n; i++)
            land[i] = {landStartTime[i], landDuration[i]};

        for (int i = 0; i < m; i++)
            water[i] = {waterStartTime[i], waterDuration[i]};

        sort(land.begin(), land.end(),
             [](const Ride& a, const Ride& b) {
                 return a.start < b.start;
             });

        sort(water.begin(), water.end(),
             [](const Ride& a, const Ride& b) {
                 return a.start < b.start;
             });

        vector<int> landStarts(n);
        vector<int> waterStarts(m);

        vector<int> landPrefMinDur(n);
        vector<int> waterPrefMinDur(m);

        vector<int> landSuffMinFinish(n);
        vector<int> waterSuffMinFinish(m);

        for (int i = 0; i < n; i++) {
            landStarts[i] = land[i].start;
        }

        for (int i = 0; i < m; i++) {
            waterStarts[i] = water[i].start;
        }

        landPrefMinDur[0] = land[0].dur;
        for (int i = 1; i < n; i++) {
            landPrefMinDur[i] =
                min(landPrefMinDur[i - 1], land[i].dur);
        }

        waterPrefMinDur[0] = water[0].dur;
        for (int i = 1; i < m; i++) {
            waterPrefMinDur[i] =
                min(waterPrefMinDur[i - 1], water[i].dur);
        }

        landSuffMinFinish[n - 1] =
            land[n - 1].start + land[n - 1].dur;

        for (int i = n - 2; i >= 0; i--) {
            landSuffMinFinish[i] = min(
                landSuffMinFinish[i + 1],
                land[i].start + land[i].dur
            );
        }

        waterSuffMinFinish[m - 1] =
            water[m - 1].start + water[m - 1].dur;

        for (int i = m - 2; i >= 0; i--) {
            waterSuffMinFinish[i] = min(
                waterSuffMinFinish[i + 1],
                water[i].start + water[i].dur
            );
        }

        long long ans = LLONG_MAX;

        ans = min(
            ans,
            evaluate(
                landStartTime,
                landDuration,
                waterStarts,
                waterPrefMinDur,
                waterSuffMinFinish
            )
        );

        ans = min(
            ans,
            evaluate(
                waterStartTime,
                waterDuration,
                landStarts,
                landPrefMinDur,
                landSuffMinFinish
            )
        );

        return (int)ans;
    }
};