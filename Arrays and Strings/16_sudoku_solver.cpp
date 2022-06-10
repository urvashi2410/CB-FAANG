class Solution {
public:
    bool isValid(vector<vector<char>> &board, int row, int col, char val){
        for(int i = 0; i < 9; i++){
            if(board[i][col] == val){
                return false;
            }
        }
        for(int j = 0; j < 9; j++){
            if(board[row][j] == val){
                return false;
            }
        }

        int startX = 3*(row/3);
        int startY = 3*(col/3);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i + startX][j + startY] == val){
                    return false;
                }
            }
        }
        return true;
    }
    bool _solveSudoko(vector<vector<char>> &board, int i, int j){
        if(i == 9){
            return true;
        }
        if(j == 9){
            return _solveSudoko(board, i+1, 0);
        }
        if(board[i][j] != '.'){
            return _solveSudoko(board, i, j+1);
        }
        else{
            for(char c = '1'; c <= '9'; c++){
                if(isValid(board, i, j, c)){
                    board[i][j] = c;
                    if(_solveSudoko(board, i, j+1)){
                        return true;
                    }
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        _solveSudoko(board, 0, 0);
    }
};