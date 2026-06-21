class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int x : costs) {
            mini = min(mini, x);
            maxi = max(maxi, x);
        }

        // counting array
        vector<int> freq(maxi - mini + 1, 0);

        for(int x : costs) {
            freq[x - mini]++;
        }

        int cnt = 0;

        // traverse prices in sorted order
        for(int i = 0; i < freq.size(); i++) {

            int price = i + mini;

            while(freq[i] > 0 && coins >= price) {
                coins -= price;
                cnt++;
                freq[i]--;
            }

            // cannot afford this or any larger price
            if(coins < price)
                break;
        }

        return cnt;
    }
};