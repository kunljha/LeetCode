class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = s;
        
        vector<int> left(n, 0), upper(2 * n - 1, 0), lower(2 * n - 1, 0);
        
        solve(0, n, left, upper, lower, board, ans);
        
        return ans;    
    }
    
    void solve(int col, int n, vector<int> &left, vector<int> &upper, vector<int> &lower, vector<string> &board, vector<vector<string>> &ans) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        
        for (int row = 0; row < n; ++row) {
              
            if (left[row] == 0 && lower[row + col] == 0 && upper[n - 1 + col - row] == 0) { // safe position to place queen

                // place the queen
                board[row][col] = 'Q';

                // mark the respective diagonals and left side(red zone) where further queens cannot be placed
                left[row] = 1;
                lower[row + col] = 1;
                upper[n - 1 + col - row] = 1;

                // recursive call to place a queen on next col 
                solve(col + 1, n, left, upper, lower, board, ans);

                // backtrack step
                board[row][col] = '.';
                left[row] = 0;
                lower[row + col] = 0;
                upper[n - 1 + col - row] = 0;
            }
        }
    }
};