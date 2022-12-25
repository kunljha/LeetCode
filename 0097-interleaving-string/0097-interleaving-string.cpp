class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        
        vector<vector<vector<int>>> dp(s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1, -1)));
        
        return fun(0, 0, 0, s1, s2, s3, dp);
    }
    
     bool fun(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<vector<int>>> &dp) {
        if(i == s1.size() && j == s2.size() && k == s3.size()) return 1;
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        
        if(i < s1.size() && s1[i] == s3[k] && j < s2.size() && s2[j] == s3[k]) {
            return dp[i][j][k] = fun(i+1, j, k+1, s1, s2, s3, dp) || fun(i, j+1, k+1, s1, s2, s3, dp);
        }
        else if(i < s1.size() && s1[i] == s3[k]) {
            return dp[i][j][k] = fun(i+1, j, k+1, s1, s2, s3, dp);
        }
        else if(j < s2.size() && s2[j] == s3[k]) {
            return dp[i][j][k] = fun(i, j+1, k+1, s1, s2, s3, dp);
        }
        else return dp[i][j][k] = 0;
    }
};