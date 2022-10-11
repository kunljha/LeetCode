class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        
        return fun(0, 0, tri, dp);
    }
    
    int fun(int i, int j, vector<vector<int>> &tri, vector<vector<int>> &dp) {
        if(i == tri.size()-1) return tri[i][j];
      
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = tri[i][j] + fun(i+1, j, tri, dp);
        int diag = tri[i][j] + fun(i+1, j+1, tri, dp);
        
        return dp[i][j] = min(down, diag);
    }
};