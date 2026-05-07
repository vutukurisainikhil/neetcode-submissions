class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> s;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    string row = to_string(board[i][j]) + " row " + to_string(i);
                    string col = to_string(board[i][j]) + " col " + to_string(j);
                    string dia =
                        to_string(board[i][j]) + " row " + to_string(i / 3) + to_string(j / 3);

                    if (!s.insert(row).second || !s.insert(col).second || !s.insert(dia).second) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
