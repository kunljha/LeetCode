class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return fun(m-1, n-1, grid, dp);
    }
    
    long long fun(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) return grid[0][0];
        
        if(i < 0 || j < 0) return INT_MAX;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        long long up = grid[i][j] + fun(i-1, j, grid, dp);
        long long left = grid[i][j] + fun(i, j-1, grid, dp);
        
        return dp[i][j] = min(up, left);   
    }
};