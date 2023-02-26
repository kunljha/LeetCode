class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        
        vector<int> prev(m+1, 0), cur(m+1, 0);  
        
        // base-case
        for(int j = 0; j <= m; ++j) prev[j] = j;
        //
        
        for(int i = 1; i <= n; ++i) {
            cur[0] = i;
            for(int j = 1; j <= m; ++j) {
                if(s1[i-1] == s2[j-1])
                    cur[j] = 0 + prev[j-1];
                else
                    cur[j] = 1 + min(prev[j], min(cur[j-1], prev[j-1]));
            }
            
            prev = cur;
        }
           
        return prev[m];
    }
    
// ----------------- memoization -------------------
//     int fun(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
//         if(i < 0) return j+1;
//         if(j < 0) return i+1;
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         if(s1[i] == s2[j]) return dp[i][j] = 0 + fun(i-1, j-1, s1, s2, dp);
        
//         return dp[i][j] = 1 + min(fun(i-1, j, s1, s2, dp),
//                        min(fun(i, j-1, s1, s2, dp), fun(i-1, j-1, s1, s2, dp)));
//     }
    
};