class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = 1;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 && j == 0) continue;
                else {
                    int up = 0, left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        
        return dp[m-1][n-1];
    }
    
//     int fun(int i , int j, vector<vector<int>> &dp) {
//         if(i < 0 || j < 0) return 0;
//         if(i == 0 && j == 0) return 1;
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         return dp[i][j] = fun(i, j-1, dp) + fun(i-1, j, dp);
//     }
};