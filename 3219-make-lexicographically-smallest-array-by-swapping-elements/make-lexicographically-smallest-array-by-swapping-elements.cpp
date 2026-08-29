class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({nums[i], i});

        sort(v.begin(), v.end());

        int l = 0;

        while (l < n) {
            int r = l;

            // Find one connected component
            while (r + 1 < n && v[r + 1].first - v[r].first <= limit)
                r++;

            // Values in this component
            vector<int> vals;
            vector<int> idx;

            for (int i = l; i <= r; i++) {
                vals.push_back(v[i].first);
                idx.push_back(v[i].second);
            }

            // Put smallest values at smallest original indices
            sort(idx.begin(), idx.end());

            for (int i = 0; i < vals.size(); i++)
                nums[idx[i]] = vals[i];

            l = r + 1;
        }

        return nums;
    }
};