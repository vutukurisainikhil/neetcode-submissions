class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {};  // rows[row][val]  = true if digit val is in row
        bool cols[9][9] = {};  // cols[col][val]  = true if digit val is in col
        bool boxes[9][9] = {}; // boxes[box][val] = true if digit val is in box

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.')
                    continue;
                int val = board[row][col] - '1';     // digit value, mapped 0..8
                int box = (row / 3) * 3 + (col / 3); // box index 0..8

                if (rows[row][val] || cols[col][val] || boxes[box][val])
                    return false;
                rows[row][val] = cols[col][val] = boxes[box][val] = true;
            }
        }
        return true;
    }
};