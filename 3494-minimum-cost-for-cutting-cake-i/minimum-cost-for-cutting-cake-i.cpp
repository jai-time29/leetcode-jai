class Solution {
public:

    vector<int> h, v;

    int dp[20][20][20][20];


    int solve(int sx, int sy, int tx, int ty) {

        // already 1x1
        if(sx == tx && sy == ty)
            return 0;


        int &ans = dp[sx][sy][tx][ty];

        if(ans != -1)
            return ans;


        ans = INT_MAX;


        // horizontal cuts
        for(int k = sx; k < tx; k++) {

            int cost =
                h[k]
                +
                solve(sx, sy, k, ty)
                +
                solve(k+1, sy, tx, ty);


            ans = min(ans, cost);
        }


        // vertical cuts
        for(int k = sy; k < ty; k++) {

            int cost =
                v[k]
                +
                solve(sx, sy, tx, k)
                +
                solve(sx, k+1, tx, ty);


            ans = min(ans, cost);
        }


        return ans;
    }


    int minimumCost(int m, int n,
                    vector<int>& horizontalCut,
                    vector<int>& verticalCut) {

        h = horizontalCut;
        v = verticalCut;

        memset(dp,-1,sizeof(dp));


        return solve(0,0,m-1,n-1);
    }
};