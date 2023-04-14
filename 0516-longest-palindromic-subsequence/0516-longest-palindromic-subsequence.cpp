class Solution {
public:
    // memoization
    int longestPalindromeSubseq(string s) {
        string s_ = s;
        reverse(s_.begin(), s_.end());
        
        return LCS(s, s_);
    }
    
    int LCS(string &s1, string &s2) {
        int n = s1.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return fun(n-1, n-1, s1, s2, dp);
    }
    
    int fun(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = 1 + fun(i-1, j-1, s1, s2, dp);
        
        return dp[i][j] = max(fun(i-1, j, s1, s2, dp), fun(i, j-1, s1, s2, dp));
    }
};