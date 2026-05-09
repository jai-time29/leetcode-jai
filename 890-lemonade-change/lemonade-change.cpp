class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        bool ans = true;
        int count5=0,count10=0,i,n=bills.size();
        for(i=0;i<n;i++){
            if(bills[i]==5)count5++;
            else if(bills[i]==10){
                if(count5>0){
                    count5--;
                    count10++;
                }
                else ans=false;
            }
            else if(bills[i]==20){
                 if(count5>0 && count10>0){
                    count5--;
                    count10--;
                }
                else  if(count5>=3){
                    count5=count5-3;
                    
                }
                else ans=false;
            }
        }
        
        return ans;
    }
};