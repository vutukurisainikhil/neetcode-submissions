class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {0};
        bool cols[9][9] = {0};
        bool boxes[9][9] = {0};

        for(int row=0;row<board.size();row++){
            for(int col=0;col<board[0].size();col++){
                if(board[row][col]=='.')
                    continue;
                int val = (board[row][col] -'0')- 1;
                int box = (row/3)*3+(col/3);

                if(rows[row][val] || cols[col][val] || boxes[box][val])
                    return false;
                
                rows[row][val]= true;
                cols[col][val]= true;
                boxes[box][val]= true;
            }
        }
        return true;
    }
};
