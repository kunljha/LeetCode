class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return paths(0, 0, m, n, dp);   
    }
    
    int paths(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i == m-1 && j == n-1) return 1;
        
        if(i == m || j == n) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        dp[i][j] = paths(i+1, j, m, n, dp) + paths(i, j+1, m, n, dp);
        
        return dp[i][j];
    }
};