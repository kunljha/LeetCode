class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        
        // without stack approach
        int i = 0, j = 0;
        while(j < n) {
            if(s[j] != '*') {
                s[i] = s[j];
                ++i;
            }
            else {
                --i;
            }
            
            ++j;
        }
        
        return s.substr(0, i);
    }
};