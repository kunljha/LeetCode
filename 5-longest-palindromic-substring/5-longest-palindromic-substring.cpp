class Solution {
private: int start, maxLen = 0;
    
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        if(n < 2) return s;
        
        for(int i = 0; i < n-1; ++i) {
            findPalindrome(s, i, i);
            findPalindrome(s, i, i+1);
        }
        
        return s.substr(start, maxLen);
    }
    
    void findPalindrome(string s, int lo, int hi) {
        while(lo >= 0 && hi < s.size() && s[lo] == s[hi])
            --lo, ++hi;
        
        if(maxLen < hi - lo - 1) {
            maxLen = hi - lo - 1,
            start = lo + 1;
        }
    }
    
};