// class Solution {
// public:

//     int dp[20][20][20][20];

//     vector<int> h, v;

//     int solve(int r1, int c1, int r2, int c2) {

//         int &res = dp[r1][c1][r2][c2];

//         if(res != -1)
//             return res;

//         if(r1 == r2 && c1 == c2)
//             return res = 0;


//         res = INT_MAX;


//         // horizontal cuts
//         for(int r = r1; r < r2; r++) {

//             res = min(
//                 res,
//                 h[r]
//                 + solve(r1,c1,r,c2)
//                 + solve(r+1,c1,r2,c2)
//             );
//         }


//         // vertical cuts
//         for(int c = c1; c < c2; c++) {

//             res = min(
//                 res,
//                 v[c]
//                 + solve(r1,c1,r2,c)
//                 + solve(r1,c+1,r2,c2)
//             );
//         }


//         return res;
//     }


//     int minimumCost(int m, int n,
//                     vector<int>& horizontalCut,
//                     vector<int>& verticalCut) {

//         h = horizontalCut;
//         v = verticalCut;

//         memset(dp,-1,sizeof(dp));


//         return solve(0,0,m-1,n-1);
//     }
// };




class Solution {
public:
    long long minimumCost(int m, int n,
                          vector<int>& horizontalCut,
                          vector<int>& verticalCut) {


        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());


        int hPieces = 1;
        int vPieces = 1;


        int i = 0;
        int j = 0;


        long long ans = 0;


        while(i < horizontalCut.size() &&
              j < verticalCut.size()) {


            if(horizontalCut[i] >= verticalCut[j]) {

                ans += 1LL * horizontalCut[i] * vPieces;

                hPieces++;
                i++;

            }
            else {

                ans += 1LL * verticalCut[j] * hPieces;

                vPieces++;
                j++;
            }
        }


        while(i < horizontalCut.size()) {

            ans += 1LL * horizontalCut[i] * vPieces;

            hPieces++;
            i++;
        }


        while(j < verticalCut.size()) {

            ans += 1LL * verticalCut[j] * hPieces;

            vPieces++;
            j++;
        }


        return ans;
    }
};