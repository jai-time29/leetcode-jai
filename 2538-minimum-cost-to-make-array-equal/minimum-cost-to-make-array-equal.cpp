class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int,int>> a;

        for (int i = 0; i < n; i++)
            a.push_back({nums[i], cost[i]});

        sort(a.begin(), a.end());

        long long total = 0;
        for (auto [x, c] : a)
            total += c;

        long long pref = 0;
        int target;

        for (auto [x, c] : a) {
            pref += c;
            if (2 * pref >= total) {
                target = x;
                break;
            }
        }

        long long ans = 0;
        for (auto [x, c] : a)
            ans += 1LL * abs(x - target) * c;

        return ans;
    }
};