class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0,cnt=0,start = 0 ;
        int n= s.length();

        for(int i=0;i<n;i++){
             if(s[i]=='(')cnt++;
             else cnt--;
             if(cnt<0){
                start=i+1,
                cnt=0;
             }
             if(cnt==0){
                 ans= max(ans,i-start+1);
             }
        }

        cnt=0,start=n-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')')cnt++;
            else cnt--;
            if(cnt<0){
                start = i-1;
                cnt=0;
            }
            if(cnt==0){
                ans=max(ans,start-i+1);
            }
        }
     return ans;
    }
};