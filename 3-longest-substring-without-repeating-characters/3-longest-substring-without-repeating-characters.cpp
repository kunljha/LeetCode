class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        
        unordered_map<char, int> ump;
        
        int i = 0, j = 0;
        while(j < s.size()) {
            ++ump[s[j]];
            
            if(ump.size() < j-i+1) {
                while(ump.size() < j-i+1) {
                    --ump[s[i]];
                    
                    if(ump[s[i]] == 0) 
                        ump.erase(s[i]);
                    
                    ++i;
                }
                
                ++j;
            } else if(ump.size() == j-i+1) {
                ans = max(ans, j-i+1);
                ++j;
            }
        }
        
        return ans;
    }
};