class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int nextBuy = 0;
        int nextHold = 0;
        int nextCooldown = 0;


        for(int i=n-1;i>=0;i--){

            int currBuy = max(
                -prices[i] + nextHold,
                nextBuy
            );


            int currHold = max(
                prices[i] + nextCooldown,
                nextHold
            );


            int currCooldown = nextBuy;


            nextBuy = currBuy;
            nextHold = currHold;
            nextCooldown = currCooldown;
        }


        return nextBuy;
    }
};