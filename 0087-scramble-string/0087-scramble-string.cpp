class Solution {
public:
    // Memoization
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> ump;
        
        return fun(s1, s2, ump);
    }
    
    bool fun(string s1, string s2, unordered_map<string, bool> &ump) {
        int n = s1.size();
        
        if(s1 == s2) return true;
        if(n <= 1) return false;
        
        string key = s1;
        key += ' ';
        key += s2;
        if(ump.count(key)) return ump[key];
        
        bool flag = false;
        for(int i = 1; i <= n-1; ++i) {
            bool swap = fun(s1.substr(0, i), s2.substr(n-i, i), ump) && fun(s1.substr(i, n-i), s2.substr(0, n-i), ump);
            bool no_swap = fun(s1.substr(0, i), s2.substr(0, i), ump) && fun(s1.substr(i, n-i), s2.substr(i, n-i), ump);
            
            if(swap || no_swap) {
                flag = true;
                break;
            }
        }
        
        return ump[key] = flag;
    }
    
};