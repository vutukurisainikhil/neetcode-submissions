class Solution {
public:
    // Reversing the matrix flips it upside down
    // Transposing swaps rows with columns
    // TimeComplexity: O(n^2)
    void rotate(vector<vector<int>>& matrix) {
        // Reverse the matrix vertically
        reverse(matrix.begin(), matrix.end());

        // Transpose the matrix
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};