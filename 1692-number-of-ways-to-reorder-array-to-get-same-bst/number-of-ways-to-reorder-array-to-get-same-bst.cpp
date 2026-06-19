class Solution {
public:

    const long long MOD = 1e9 + 7;

    vector<vector<long long>> C;


    long long solve(vector<int>& nums) {

        int n = nums.size();

        // one possible ordering for empty/single node tree
        if(n <= 2)
            return 1;


        int root = nums[0];

        vector<int> left;
        vector<int> right;


        for(int i = 1; i < n; i++) {

            if(nums[i] < root)
                left.push_back(nums[i]);

            else
                right.push_back(nums[i]);
        }


        long long leftWays = solve(left);
        long long rightWays = solve(right);


        // choose positions for left and right subtree elements
        long long waysToArrangeChildren =
            C[left.size() + right.size()][left.size()];


        return (((waysToArrangeChildren * leftWays) % MOD)
                    * rightWays) % MOD;
    }


    int numOfWays(vector<int>& nums) {

        int n = nums.size();


        // Pascal triangle for combinations
        C.assign(n + 1, vector<long long>(n + 1, 0));


        for(int i = 0; i <= n; i++) {

            C[i][0] = 1;
            C[i][i] = 1;


            for(int j = 1; j < i; j++) {

                C[i][j] =
                    (C[i-1][j-1] + C[i-1][j]) % MOD;
            }
        }


        long long ans = solve(nums);


        // remove original ordering
        return (ans - 1 + MOD) % MOD;
    }
};