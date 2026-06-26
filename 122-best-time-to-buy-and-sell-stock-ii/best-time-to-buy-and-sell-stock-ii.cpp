// class Solution {
// public:
//     // 
//     int maxProfit(vector<int>& prices) {
//         int profit = 0;

//         for(int i = 1; i < prices.size(); i++) {
//             if(prices[i] > prices[i-1]) {
//                 profit += prices[i] - prices[i-1];
//             }
//         }

//         return profit;
//     }
// };
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();

        int nextBuy=0;
        int nextSell=0;


        for(int i=n-1;i>=0;i--){

            int currBuy=max(
                -prices[i]+nextSell,
                nextBuy
            );


            int currSell=max(
                prices[i]+nextBuy,
                nextSell
            );


            nextBuy=currBuy;
            nextSell=currSell;
        }


        return nextBuy;
    }
};