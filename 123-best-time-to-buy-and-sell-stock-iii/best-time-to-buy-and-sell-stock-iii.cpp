// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         long profit=0;
//         int n= prices.size();
//         vector<int>curr(4,0),ahead(4,0);
        
//         for(int i=n-1;i>=0;i--){
//             for(int trans=1;trans<=3;trans++){
//                if(trans%2==0) curr[trans]=max(ahead[trans+1]-prices[i],0+ahead[trans]);
//                else curr[trans]=max(prices[i]+ahead[trans+1],ahead[trans]);
              
//             }

//             ahead=curr;
//         }
//         return ahead[0];
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<long> ahead(5,0);
        vector<long> curr(5,0);


        for(int i=n-1;i>=0;i--){

            for(int trans=0;trans<4;trans++){

                if(trans%2==0){ 
                    // buy
                    curr[trans]=max(
                        -prices[i]+ahead[trans+1],
                        ahead[trans]
                    );
                }
                else{
                    // sell
                    curr[trans]=max(
                        prices[i]+ahead[trans+1],
                        ahead[trans]
                    );
                }
            }

            ahead=curr;
        }


        return ahead[0];
    }
};