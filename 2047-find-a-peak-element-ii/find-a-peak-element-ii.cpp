class Solution {
public:

    int findMaxRow(
        vector<vector<int>>& mat,
        int col) {

        int row = 0;

        for (int i = 0;
             i < mat.size();
             i++) {

            if (mat[i][col] >
                mat[row][col]) {

                row = i;
            }
        }

        return row;
    }

    vector<int> findPeakGrid(
        vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int midCol =
                low + (high - low) / 2;

            int maxRow =
                findMaxRow(mat, midCol);

            int left =
                (midCol - 1 >= 0)
                ? mat[maxRow][midCol - 1]
                : -1;

            int right =
                (midCol + 1 < n)
                ? mat[maxRow][midCol + 1]
                : -1;

            int curr =
                mat[maxRow][midCol];

            // peak found
            if (curr > left &&
                curr > right) {

                return {
                    maxRow,
                    midCol
                };
            }

            // move left
            else if (left > curr) {

                high = midCol - 1;
            }

            // move right
            else {

                low = midCol + 1;
            }
        }

        return {-1, -1};
    }
};