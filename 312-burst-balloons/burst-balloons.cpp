class Solution {
public:
    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(),1);
        nums.push_back(1);

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n,0));

        for(int len=1; len<=n-2; len++){

            for(int i=1; i+len-1<=n-2; i++){

                int j=i+len-1;

                for(int k=i;k<=j;k++){

                    dp[i][j]=max(dp[i][j],
                        dp[i][k-1]
                      + dp[k+1][j]
                      + nums[i-1]*nums[k]*nums[j+1]);
                }
            }
        }

        return dp[1][n-2];
    }
};