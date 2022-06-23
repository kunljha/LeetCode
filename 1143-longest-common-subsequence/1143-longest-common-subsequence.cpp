class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return lcs(s1, s2, m-1, n-1, dp);
    }
    
    int lcs(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = 1 + lcs(s1, s2, i-1, j-1, dp);
        
        return dp[i][j] = max(lcs(s1, s2, i-1, j, dp), lcs(s1, s2, i, j-1, dp));
    }
};