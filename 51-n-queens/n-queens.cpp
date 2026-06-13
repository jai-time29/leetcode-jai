class Solution {
public:

    vector<vector<string>> ans;
    vector<string> board;

    vector<int> col;
    vector<int> diag1;
    vector<int> diag2;

    int n;


    void solve(int row) {

        if(row == n) {
            ans.push_back(board);
            return;
        }


        for(int c = 0; c < n; c++) {

            // check column
            if(col[c])
                continue;

            // check diagonals
            if(diag1[row-c+n-1])
                continue;

            if(diag2[row+c])
                continue;


            // place queen
            board[row][c] = 'Q';

            col[c] = 1;
            diag1[row-c+n-1] = 1;
            diag2[row+c] = 1;


            solve(row+1);


            // backtrack
            board[row][c] = '.';

            col[c] = 0;
            diag1[row-c+n-1] = 0;
            diag2[row+c] = 0;
        }
    }


    vector<vector<string>> solveNQueens(int n) {

        this->n = n;

        board = vector<string>(n, string(n,'.'));

        col.assign(n,0);
        diag1.assign(2*n-1,0);
        diag2.assign(2*n-1,0);


        solve(0);

        return ans;
    }
};