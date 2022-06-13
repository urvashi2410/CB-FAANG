class Solution {
public:
    int n = 9;
    bool _isValidSudoku(vector<vector<char>> &board, int row, int col){
        for(int i = 0; i < n; i++){
            if(i != row){
                if(board[i][col] == board[row][col]){
                    return false;
                }
            }
        }

        for(int j = 0; j < n; j++){
            if(j != col){
                if(board[row][j] == board[row][col]){
                    return false;
                }
            }
        }

        int startX = 3*(row/3);
        int startY = 3*(col/3);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i + startX != row && j + startY != col){
                    if(board[i + startX][j + startY] == board[row][col]){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != '.'){
                    if(!_isValidSudoku(board, i, j)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};