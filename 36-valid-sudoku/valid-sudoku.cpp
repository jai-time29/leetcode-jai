/*  class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for(int i = 0; i < 9; i++) {

            for(int j = 0; j < 9; j++) {

                char ch = board[i][j];

                if(ch == '.')
                    continue;

                int box = (i / 3) * 3 + (j / 3);

                // duplicate found
                if(rows[i].count(ch) ||
                   cols[j].count(ch) ||
                   boxes[box].count(ch)) {

                    return false;
                }

                rows[i].insert(ch);
                cols[j].insert(ch);
                boxes[box].insert(ch);
            }
        }

        return true;
    }
}; */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<int> rows(9, 0);
        vector<int> cols(9, 0);
        vector<int> boxes(9, 0);

        for(int i = 0; i < 9; i++) {

            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';

                int mask = 1 << num;

                int box = (i / 3) * 3 + (j / 3);

                // already exists
                if((rows[i] & mask) ||
                   (cols[j] & mask) ||
                   (boxes[box] & mask)) {

                    return false;
                }

                // mark present
                rows[i] |= mask;
                cols[j] |= mask;
                boxes[box] |= mask;
            }
        }

        return true;
    }
};