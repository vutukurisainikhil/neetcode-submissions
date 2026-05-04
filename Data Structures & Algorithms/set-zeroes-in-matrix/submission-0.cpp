class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();

        vector<int> row;
        vector<int> col;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (matrix[i][j] == 0) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        for (auto ro : row) {
            for (int j = 0; j < c; ++j) {
                matrix[ro][j] = 0;
            }
        }

        for (auto co : col) {
            for (int i = 0; i < r; ++i) {
                matrix[i][co] = 0;
            }
        }
    }
};