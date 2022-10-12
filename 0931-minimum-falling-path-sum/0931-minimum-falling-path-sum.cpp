class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
      int n = mat.size(); // given square matrix rows == cols
      
      int ans = 1e9;
      vector<vector<int>> dp(n, vector<int>(n, -1));
      
      for(int j = 0; j < n; ++j)
        ans = min(ans, fun(n-1, j, mat, dp));
      
      return ans;
    }
  
    int fun(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
      if(j < 0 || j == mat[0].size()) return 1e9;
      
      if(i == 0) return mat[i][j];
      
      if(dp[i][j] != -1) return dp[i][j];
      
      int down = mat[i][j] + fun(i-1, j, mat, dp);
      int left_diag = mat[i][j] + fun(i-1, j-1, mat, dp);
      int right_diag = mat[i][j] + fun(i-1, j+1, mat, dp);
      
      return dp[i][j] = min(down, min(left_diag, right_diag));
    }
};