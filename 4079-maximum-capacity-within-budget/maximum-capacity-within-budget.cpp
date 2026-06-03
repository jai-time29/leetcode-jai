class Solution {
public:
    int maxCapacity(vector<int>& costs,
                    vector<int>& capacity,
                    int budget) {

        int n = costs.size();

        vector<pair<int,int>> machines;

        for(int i = 0; i < n; i++) {
            machines.push_back({costs[i], capacity[i]});
        }

        sort(machines.begin(), machines.end());

        vector<int> pref(n);

        pref[0] = machines[0].second;

        for(int i = 1; i < n; i++) {
            pref[i] = max(pref[i-1],
                          machines[i].second);
        }

        int ans = 0;

        // one machine
        for(int i = 0; i < n; i++) {
            if(machines[i].first < budget) {
                ans = max(ans,
                          machines[i].second);
            }
        }

        // two machines
        for(int i = 1; i < n; i++) {

            int limit = budget - machines[i].first;

            int l = 0;
            int r = i - 1;

            int idx = -1;

            while(l <= r) {

                int mid = l + (r - l) / 2;

                if(machines[mid].first < limit) {
                    idx = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }

            if(idx != -1) {

                ans = max(ans,
                          machines[i].second +
                          pref[idx]);
            }
        }

        return ans;
    }
};