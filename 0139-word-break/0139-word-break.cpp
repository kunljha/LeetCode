class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        
        unordered_set<string> dict;
        for(string str : wordDict) {
            dict.insert(str);
        }
        
        vector<int> dp(n+1, -1);
        
        return fun(0, s, dict, dp); 
    }
    
    bool fun(int ind, string &s, unordered_set<string> &dict, vector<int> &dp) {
        if(ind == s.size()) return 1;
        
        if(dp[ind] != -1) return dp[ind];
        
        for(int j = ind; j < (int)s.size(); ++j) {
            string prefix = s.substr(ind, j-ind+1);
            
            if(dict.count(prefix) && fun(j+1, s, dict, dp)) {
                return dp[ind] = 1;
            }
        }
        
        return dp[ind] = 0;
    }
};