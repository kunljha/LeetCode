class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        
        unordered_set<string> ust;
        for(string str : wordDict) {
            ust.insert(str);
        }
        
        vector<int> dp(n, -1);
        
        return fun(0, s, ust, dp); 
    }
    
    bool fun(int ind, string &s, unordered_set<string> &ust, vector<int> &dp) {
        if(ind == s.size()) return 1;
        
        if(dp[ind] != -1) return dp[ind];
        
        for(int j = ind; j < s.size(); ++j) {
            string cur_word = s.substr(ind, j-ind+1);
            
            if(ust.find(cur_word) == ust.end()) continue;
            
            if(fun(j+1, s, ust, dp)) {
                return dp[ind] = 1;
            }
        }
        
        return dp[ind] = 0;
    }
};