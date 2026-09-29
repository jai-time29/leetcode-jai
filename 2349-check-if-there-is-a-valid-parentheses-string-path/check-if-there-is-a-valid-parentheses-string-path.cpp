class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        int len=m+n-1;
       
        if(grid[0][0]==')' || len%2==1)return false;
        vector<vector<vector<bool>>>dp(n,vector<vector<bool>>(m,vector<bool>(len+1,false)));
        dp[0][0][1]=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)continue;
                int shift = (grid[i][j]=='('? 1 : -1 );
                for(int balance = 0;balance<=len;balance++){
                    
                    int next = balance+shift;
                    if(next<0 || next>len)continue;
                    if (i > 0 && dp[i-1][j][balance])
                        dp[i][j][next] = true;

                    if (j > 0 && dp[i][j-1][balance])
                        dp[i][j][next] = true;
                }
            }
        }
        return dp[n-1][m-1][0];
    }
};