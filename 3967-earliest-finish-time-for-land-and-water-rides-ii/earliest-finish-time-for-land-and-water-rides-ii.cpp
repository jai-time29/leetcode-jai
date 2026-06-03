class Solution {
public:

    struct Ride {
        int start;
        int dur;
    };

    long long solve(const vector<int>& startA,
                    const vector<int>& durA,
                    const vector<int>& startsB,
                    const vector<int>& prefDurB,
                    const vector<int>& suffFinishB) {

        int m = startsB.size();
        long long ans = LLONG_MAX;

        for(int i = 0; i < startA.size(); i++) {

            long long finishA = (long long)startA[i] + durA[i];

            int pos = upper_bound(
                startsB.begin(),
                startsB.end(),
                finishA
            ) - startsB.begin();

            if(pos > 0) {
                ans = min(
                    ans,
                    finishA + (long long)prefDurB[pos - 1]
                );
            }

            if(pos < m) {
                ans = min(
                    ans,
                    (long long)suffFinishB[pos]
                );
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<Ride> land(n), water(m);

        for(int i = 0; i < n; i++)
            land[i] = {landStartTime[i], landDuration[i]};

        for(int i = 0; i < m; i++)
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

        vector<int> landPrefDur(n);
        vector<int> waterPrefDur(m);

        vector<int> landSuffFinish(n);
        vector<int> waterSuffFinish(m);

        for(int i = 0; i < n; i++)
            landStarts[i] = land[i].start;

        for(int i = 0; i < m; i++)
            waterStarts[i] = water[i].start;

        landPrefDur[0] = land[0].dur;
        for(int i = 1; i < n; i++)
            landPrefDur[i] =
                min(landPrefDur[i - 1], land[i].dur);

        waterPrefDur[0] = water[0].dur;
        for(int i = 1; i < m; i++)
            waterPrefDur[i] =
                min(waterPrefDur[i - 1], water[i].dur);

        landSuffFinish[n - 1] =
            land[n - 1].start + land[n - 1].dur;

        for(int i = n - 2; i >= 0; i--) {
            landSuffFinish[i] = min(
                landSuffFinish[i + 1],
                land[i].start + land[i].dur
            );
        }

        waterSuffFinish[m - 1] =
            water[m - 1].start + water[m - 1].dur;

        for(int i = m - 2; i >= 0; i--) {
            waterSuffFinish[i] = min(
                waterSuffFinish[i + 1],
                water[i].start + water[i].dur
            );
        }

        long long ans = LLONG_MAX;

        // Land -> Water
        ans = min(
            ans,
            solve(
                landStartTime,
                landDuration,
                waterStarts,
                waterPrefDur,
                waterSuffFinish
            )
        );

        // Water -> Land
        ans = min(
            ans,
            solve(
                waterStartTime,
                waterDuration,
                landStarts,
                landPrefDur,
                landSuffFinish
            )
        );

        return (int)ans;
    }
};