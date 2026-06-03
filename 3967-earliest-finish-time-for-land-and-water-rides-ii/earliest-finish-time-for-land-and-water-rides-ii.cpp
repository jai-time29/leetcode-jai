class Solution {
public:

    long long solve(vector<int>& Astart, vector<int>& Adur,
                    vector<int>& Bstart, vector<int>& Bdur) {

        int m = Bstart.size();

        vector<pair<long long,long long>> rides;

        for(int i = 0; i < m; i++) {
            rides.push_back({Bstart[i], Bdur[i]});
        }

        sort(rides.begin(), rides.end());

        vector<long long> starts(m);

        for(int i = 0; i < m; i++) {
            starts[i] = rides[i].first;
        }

        // pref[i] = minimum duration in [0..i]
        vector<long long> pref(m);

        pref[0] = rides[0].second;

        for(int i = 1; i < m; i++) {
            pref[i] = min(pref[i - 1], rides[i].second);
        }

        // suff[i] = minimum (start + duration) in [i..m-1]
        vector<long long> suff(m);

        suff[m - 1] = rides[m - 1].first + rides[m - 1].second;

        for(int i = m - 2; i >= 0; i--) {

            suff[i] = min(
                suff[i + 1],
                rides[i].first + rides[i].second
            );
        }

        long long ans = LLONG_MAX;

        for(int i = 0; i < (int)Astart.size(); i++) {

            long long finishFirst =
                (long long)Astart[i] + Adur[i];

            int pos = upper_bound(
                starts.begin(),
                starts.end(),
                finishFirst
            ) - starts.begin();

            // start <= finishFirst
            if(pos > 0) {

                ans = min(
                    ans,
                    finishFirst + pref[pos - 1]
                );
            }

            // start > finishFirst
            if(pos < m) {

                ans = min(
                    ans,
                    suff[pos]
                );
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long ans = LLONG_MAX;

        // Land -> Water
        ans = min(ans,
                  solve(landStartTime,
                        landDuration,
                        waterStartTime,
                        waterDuration));

        // Water -> Land
        ans = min(ans,
                  solve(waterStartTime,
                        waterDuration,
                        landStartTime,
                        landDuration));

        return (int)ans;
    }
};