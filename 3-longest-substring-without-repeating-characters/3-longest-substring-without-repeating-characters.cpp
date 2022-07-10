class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        
        unordered_set<char> hash;
        
        int l = 0, r = 0;
        while(l <= r && r < s.size()) {
            if(!hash.count(s[r])) 
                hash.insert(s[r]),
                len = max(r - l + 1, len),
                ++r;
            else 
                hash.erase(s[l]),
                ++l;
        }
        
        return len;
    }
};