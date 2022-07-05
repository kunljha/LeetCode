class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return unique(m, n, 0, 0, dp);
    }
    
    int unique(int m, int n, int i, int j, vector<vector<int>> &dp) {
        if(i == m || j == n) return 0; // out of bound
        
        if(i == m-1 && j == n-1) return 1; // reached destination
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = unique(m, n, i+1, j, dp) + unique(m, n, i, j+1, dp);
    }
};