class Solution {
// private: int start, maxLen = 0;
    
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        if(n < 2) return s;
        
        pair<int, int> p; // p.first = start, p.second = maxLen
        
        for(int i = 0; i < n-1; ++i) {
            findPalindrome(s, p, i, i);
            findPalindrome(s, p, i, i+1);
        }
        
        return s.substr(p.first, p.second);
    }
    
    void findPalindrome(string s, pair<int, int> &p, int lo, int hi) {
        while(lo >= 0 && hi < s.size() && s[lo] == s[hi])
            --lo, ++hi;
        
        if(p.second < hi - lo - 1) {
            p.second = hi - lo - 1,
            p.first = lo + 1;
        }
    }
    
};