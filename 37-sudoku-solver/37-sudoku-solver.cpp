class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>> &board) {
        
        for(int i = 0; i < board.size(); ++i) {
            
            for(int j = 0; j < board[0].size(); ++j) {
                
                if(board[i][j] == '.') {
                    
                    for(char c = '1'; c <= '9'; ++c) {
                        if(isValid(board, c, i, j)) {
                            board[i][j] = c;

                            if(solve(board))
                                return true; // means valid solution

                            // backtrack
                            board[i][j] = '.' ;
                        }  
                    }
                    
                    return false;
                }
                
            }
            
         }
        
        return true;
    }
    
    bool isValid(vector<vector<char>> &board, char c, int row, int col) {
        int startRow = 3 * (row / 3);  // region start row
        int startCol = 3 * (col / 3);  // region start col
        
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) return false; //check row
            if (board[i][col] == c) return false; //check column
            if (board[startRow + i / 3][startCol + i % 3] == c) return false;  //check 3*3 block
        }
        
        return true;
    }
};