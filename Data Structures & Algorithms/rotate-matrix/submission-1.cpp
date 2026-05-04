class Solution {
public:
    /* First Transpose: transpose the matrix
       Second Reflect: interchange diagonal matrix elements
    */
    void rotate(vector<vector<int>>& matrix) {
       
         reverse(matrix.begin(), matrix.end());
          transpose(matrix);
    }
    /*
    1 2 3       1 4 7      7 4 1
    4 5 6  ->   2 5 8  ->  8 5 2
    7 8 9       3 6 9      9 6 3
    */
    
    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) { // Here j=i
                int tmp = matrix[j][i];
                // Transpose
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
    }
    
    // void reflect(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < n / 2; j++) {
    //             //Interchange the last columns elements
    //             int tmp = matrix[i][j];
    //             matrix[i][j] = matrix[i][n - j - 1];
    //             matrix[i][n - j - 1] = tmp;
    //         }
    //     }
    // }  
};