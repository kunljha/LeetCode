class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        
        int i = 0, j = 0, idx = 0;
        while(i < n && j < m) {
            if(haystack[i] == needle[j]) {
                ++i, ++j;
            }
            else {
                j = 0, 
                i = ++idx;
            }
        }
        
        return (j == m ? idx : -1);      
    }
};