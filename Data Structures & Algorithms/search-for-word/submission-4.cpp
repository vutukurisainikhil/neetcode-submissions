class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(dfs(i, j, board, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int i, int j, vector<vector<char>>& boards, string word, int index){
        if(index >= word.size()){
            return true;
        }
        if(i<0 || i >= boards.size() || j<0 || j >= boards[0].size()){
            return false;
        }

        if(boards[i][j] != word[index]){
            return false;
        }

        if(boards[i][j] == '*'){
            return false;
        }

        int val = boards[i][j];
        boards[i][j] = '*';

        bool res = dfs(i+1, j, boards, word, index+1) || 
                    dfs(i-1, j, boards, word, index+1) ||
                    dfs(i, j+1, boards, word, index+1)||
                    dfs(i, j-1, boards, word, index+1);
        boards[i][j] = val;
        return res;
    
    }   
};
