class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> prev(n, 1), cur(n, 0);
        
        for(int i = 1; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int up = prev[j];
                int left = 0;
                if(j > 0) left = cur[j-1];
                
                cur[j] = up + left;
            } 
            prev = cur;
        }
        
        return prev[n-1];
    }
    
//     int fun(int i , int j, vector<vector<int>> &dp) {
//         if(i < 0 || j < 0) return 0;
//         if(i == 0 && j == 0) return 1;
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         return dp[i][j] = fun(i, j-1, dp) + fun(i-1, j, dp);
//     }
};