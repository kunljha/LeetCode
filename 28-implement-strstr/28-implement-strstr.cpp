class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;
        
        int n = haystack.size(), m = needle.size();
        
        for(int i = 0; i <= n-m; ++i) {
            int j = 0;
            for(; j < m; ++j) {
                if(needle[j] == haystack[i+j])
                    continue;
                else 
                    break;
            }
            
            if(j == m)
                return i;        
        }
        
        return -1;
     }
};