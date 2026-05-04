class Solution {
public:
    // TimeComplexity: O(m*n)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if(matrix.size()==0){
            return v;
        }
        int dir = 0; 
        int top=0, bottom=matrix.size()-1, left = 0, right=matrix[0].size()-1;
        while(top<=bottom && left <= right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    v.push_back(matrix[top][i]);
                }
                top++;
            }
            if(dir==1){
                for(int i=top;i<=bottom;i++){
                    v.push_back(matrix[i][right]);
                }
                right--;
            }
            if(dir==2){
                for(int i=right;i>=left;i--){
                    v.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(dir==3){
                for(int i=bottom;i>=top;i--){
                    v.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            dir = dir%4;
        }
        return v;
    }
};