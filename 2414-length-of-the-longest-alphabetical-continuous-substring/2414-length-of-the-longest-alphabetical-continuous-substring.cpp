class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 0;
        string S = "abcdefghijklmnopqrstuvwxyz";
        
        int i = 0, j = 0;
        while(j < s.size()) {
            if(S.find(s.substr(i, j-i+1)) != string::npos) {
                ans = max(ans, j-i+1);
                ++j;
            } else {
                i = j;
            }
        }
     
        return ans;
    }
};