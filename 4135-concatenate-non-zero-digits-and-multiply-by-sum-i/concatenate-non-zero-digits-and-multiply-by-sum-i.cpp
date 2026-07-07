class Solution {
public:
    long long sumAndMultiply(int n) {
        string s= to_string(n);
        long long ans=0,sum=0;;
        int cnt=0;
        for(char c : s){
            if(c=='0')cnt++;
            else{ 
                ans = ans*10 + (c- '0');
                sum+=(c-'0');
        }
        }
        
         ans=ans*sum;
        return ans;
    }
};