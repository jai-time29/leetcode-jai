class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {

        int n = prices.size();

        const long long NEG = -1e18;

        // free[t] -> completed t transactions, no active transaction
        // buy[t] -> completed t transactions, currently holding a normal buy
        // shortSell[t] -> completed t transactions, currently holding a short position

        vector<long long> free(k + 1, NEG);
        vector<long long> buy(k + 1, NEG);
        vector<long long> shortSell(k + 1, NEG);

        free[0] = 0;

        for(int price : prices) {

            vector<long long> prevFree = free;
            vector<long long> prevBuy = buy;
            vector<long long> prevShort = shortSell;


            for(int t = 0; t <= k; t++) {

                // Stay in the same state
                free[t] = max(free[t], prevFree[t]);
                buy[t] = max(buy[t], prevBuy[t]);
                shortSell[t] = max(shortSell[t], prevShort[t]);


                // Start normal transaction: buy stock
                if(prevFree[t] != NEG) {
                    buy[t] = max(buy[t],
                                 prevFree[t] - price);
                }


                // Start short transaction: sell stock first
                if(prevFree[t] != NEG) {
                    shortSell[t] = max(shortSell[t],
                                       prevFree[t] + price);
                }


                // Complete normal transaction: sell stock
                if(t < k && prevBuy[t] != NEG) {
                    free[t+1] = max(free[t+1],
                                    prevBuy[t] + price);
                }


                // Complete short transaction: buy back stock
                if(t < k && prevShort[t] != NEG) {
                    free[t+1] = max(free[t+1],
                                    prevShort[t] - price);
                }
            }
        }


        long long ans = 0;

        for(int t = 0; t <= k; t++) {
            ans = max(ans, free[t]);
        }

        return ans;
    }
};