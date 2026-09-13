class Solution {
public:

    vector<vector<int>> generater_new(vector<vector<int>>& mat,
                                      int r, int c) {

        int n = mat.size();
        vector<vector<int>> temp(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int ni = i + r;
                int nj = j + c;

                if (ni >= 0 && ni < n &&
                    nj >= 0 && nj < n)
                    temp[ni][nj] = mat[i][j];
            }
        }

        return temp;
    }

    int check_max1s(vector<vector<int>>& mat1,
                    vector<vector<int>>& mat2) {

        int n = mat1.size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cnt += mat1[i][j] && mat2[i][j];

        return cnt;
    }

    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();
        int ans = 0;

        for (int r = -(n - 1); r <= n - 1; r++) {
            for (int c = -(n - 1); c <= n - 1; c++) {

                auto temp = generater_new(img1, r, c);

                ans = max(ans, check_max1s(temp, img2));
            }
        }

        return ans;
    }
};