class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        
        if(n < 2) return s;
        
        for(int i = 0; i < n; ++i) {
            string s1 = extend(s, i, i);
            string s2 = extend(s, i, i+1);
            
            if(s1.size() > ans.size()) ans = s1;
            if(s2.size() > ans.size()) ans = s2;          
        }
        
        return ans;
    }
    
    string extend(string s, int l, int r) {
        while(l >= 0 && r < s.size() && s[l] == s[r])
            --l, ++r;
        
        return s.substr(l+1, r-l-1);
    }
    
};