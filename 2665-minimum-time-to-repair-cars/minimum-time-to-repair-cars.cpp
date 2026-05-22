class Solution {
public:

    bool canRepair(
        vector<int>& ranks,
        int cars,
        long long time) {

        long long repaired = 0;

        for (int r : ranks) {

            repaired += sqrt(time / r);

            if (repaired >= cars)
                return true;
        }

        return false;
    }

    long long repairCars(
        vector<int>& ranks,
        int cars) {

        int minRank =
            *min_element(
                ranks.begin(),
                ranks.end());

        long long low = 1;

        long long high =
            1LL * minRank * cars * cars;

        long long ans = high;

        while (low <= high) {

            long long mid =
                low + (high - low) / 2;

            if (canRepair(
                    ranks,
                    cars,
                    mid)) {

                ans = mid;

                high = mid - 1;
            }

            else {

                low = mid + 1;
            }
        }

        return ans;
    }
};