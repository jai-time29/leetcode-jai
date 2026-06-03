class Solution {
public:
    int fillCups(vector<int>& amount) {

        int total = amount[0] + amount[1] + amount[2];

        int mx = max({amount[0], amount[1], amount[2]});

        return max(mx, (total + 1) / 2);
    }
};