class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<int> ahead(2*k + 1, 0);
        vector<int> curr(2*k + 1, 0);


        for(int i=n-1;i>=0;i--){

            for(int trans=2*k-1;trans>=0;trans--){

                if(trans%2==0){
                    // buy
                    curr[trans]=max(
                        -prices[i] + ahead[trans+1],
                        ahead[trans]
                    );
                }
                else{
                    // sell
                    curr[trans]=max(
                        prices[i] + ahead[trans+1],
                        ahead[trans]
                    );
                }
            }

            ahead=curr;
        }


        return ahead[0];
    }
};