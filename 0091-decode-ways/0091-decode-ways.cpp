class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        vector<int> dp(n+2, -1);
        
        return fun(0, s, dp);
    }
    
    int fun(int i, string &s, vector<int> &dp) {
        if(i >= s.size()) return 1;
        if(s[i] == '0') return 0;
        if(i == s.size()-1) return 1;
        
        if(dp[i] != -1) return dp[i];
        
        if(s[i] == '1') {
            return dp[i] = fun(i+1, s, dp) + fun(i+2, s, dp);
        }
        
        if(s[i] == '2' && s[i+1] >= '0' && s[i+1] <= '6') {
            return dp[i] = fun(i+1, s, dp) + fun(i+2, s, dp);
        }
        
        return dp[i] = fun(i+1, s, dp);
    }
};