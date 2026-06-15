class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {}; // [number of the row, digit 1 - 9]
        bool cols[9][9] = {}; // [number of the columns, digit 1 - 9]
        bool boxes[9][9] = {}; // [number of the sub-box, digit 1 - 9]

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                char ch = board[i][j]; // i - row, j - column

                if (ch =='.') {
                    continue;
                }

                int digit = ch - '1'; //'1' -> 0, '2' -> 1
                int subBox = (i / 3) * 3 + (j / 3);

                if (rows[i][digit] || cols[j][digit] || boxes[subBox][digit]) {
                    return false;
                }
                rows[i][digit] = true;
                cols[j][digit] = true;
                boxes[subBox][digit] = true;
            }
        }
        return true;
    }
};
