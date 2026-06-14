class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {

        int rounds = minutesToTest / minutesToDie;

        int states = rounds + 1;

        int pigs = 0;

        long long possibilities = 1;

        while(possibilities < buckets) {

            possibilities *= states;
            pigs++;
        }

        return pigs;
    }
};