class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n,false));

        int start = 0;
        int maxLen = 1;


        // i should go backwards because
        // dp[i+1][j-1] must already be calculated
        for(int i=n-1;i>=0;i--){

            for(int j=i;j<n;j++){

                if(s[i]==s[j]){

                    // length <= 2
                    if(j-i <= 1)
                        dp[i][j]=true;

                    else
                        dp[i][j]=dp[i+1][j-1];
                }


                if(dp[i][j]){

                    int currLen=j-i+1;

                    if(currLen > maxLen){

                        maxLen=currLen;
                        start=i;
                    }
                }
            }
        }


        return s.substr(start,maxLen);
    }
};