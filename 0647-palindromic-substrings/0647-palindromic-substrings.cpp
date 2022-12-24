class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += extend(i, i, s) + extend(i, i+1, s);
        }
        
        return ans;
    }
    
    int extend(int l, int r, string &s) {
        int cnt = 0;
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            ++cnt,
            --l,
            ++r;
        }
        
        return cnt;
    }
};