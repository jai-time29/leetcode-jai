class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ind1=0,ind2=0,ans=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<prices[ind1]){
                
                ind1= i;
                ind2 = i;
               
            }
            else if(prices[i]>prices[ind2] && i>ind2){
                ind2 = i;
               
            }
          if(ind2>ind1){
            ans = max(prices[ind2]-prices[ind1],ans);
          }
        }
       return ans;
    }
};