class Solution {
public:

    vector<int> countDigits(int n) {

        vector<int> freq(10,0);

        while(n) {
            freq[n%10]++;
            n/=10;
        }

        return freq;
    }


    bool reorderedPowerOf2(int n) {

        vector<int> target = countDigits(n);

        long long power = 1;


        while(power <= 1e9) {

            if(countDigits(power) == target)
                return true;

            power *= 2;
        }


        return false;
    }
};