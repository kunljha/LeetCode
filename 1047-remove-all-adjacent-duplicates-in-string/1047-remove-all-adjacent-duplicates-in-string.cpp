class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        int i = 0;
        for(int j = 0; j < n; ++j) {
            s[i] = s[j];
            if(i > 0 && s[i] == s[i-1]) i -= 2;
            ++i;
        }
        
        return s.substr(0, i);      
    }
};