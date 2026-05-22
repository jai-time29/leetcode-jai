class Solution {
public:

    int maximumBags(
        vector<int>& capacity,
        vector<int>& rocks,
        int additionalRocks) {

        int n = capacity.size();

        vector<int> need;

        for (int i = 0; i < n; i++) {

            need.push_back(
                capacity[i] - rocks[i]
            );
        }

        sort(need.begin(), need.end());

        int full = 0;

        for (int x : need) {

            if (x <= additionalRocks) {

                additionalRocks -= x;

                full++;
            }

            else {

                break;
            }
        }

        return full;
    }
};