class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        
        return fun(s1.size()-1, s2.size()-1, s3.size()-1, s1, s2, s3, dp);
    }
    
    bool fun(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<int>> &dp) {
        if(i < 0 && j < 0 && k < 0) return 1;
        
        if(i >= 0 && j >= 0 && dp[i][j] != -1) return dp[i][j];
          
        if(i >= 0 && s1[i] == s3[k] && j >= 0 && s2[j] == s3[k])
            return dp[i][j] = fun(i-1, j, k-1, s1, s2, s3, dp) || fun(i, j-1, k-1, s1, s2, s3, dp);
        
        else if(i >= 0 && s1[i] == s3[k])
            return fun(i-1, j, k-1, s1, s2, s3, dp);
        
        else if(j >= 0 && s2[j] == s3[k])
            return fun(i, j-1, k-1, s1, s2, s3, dp);
        
        else return 0;
    }
};