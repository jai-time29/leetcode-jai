class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        int nextBuy = 0;
        int nextHold = 0;


        for(int i=prices.size()-1;i>=0;i--){

            int currBuy=max(
                -prices[i]+nextHold,
                nextBuy
            );


            int currHold=max(
                prices[i]-fee+nextBuy,
                nextHold
            );


            nextBuy=currBuy;
            nextHold=currHold;
        }


        return nextBuy;
    }
};