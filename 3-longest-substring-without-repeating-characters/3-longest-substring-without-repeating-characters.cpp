class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        
        unordered_map<char, int> hash;
        
        int l = 0, r = 0;
        while(r < s.size()) {
            if(hash.count(s[r])) 
                l = max(hash[s[r]] + 1, l);
            
            len = max(r - l + 1, len),
            hash[s[r]] = r,
            ++r;
        }
        
        return len;
    }
};