class Solution {
public:
    int partitionString(string s) {
        unordered_map<char, int> ump;
        
        int ans = 0;
        int i = 0, j = 0, freqs = 0;
        while(j < s.size()) {
            ++ump[s[j]];
            ++freqs;
            
            if(freqs > ump.size()) {
                i = j;
                ump.clear();
                freqs = 0;
                ++ans;
            }
            else ++j;
            
        }
        
        return ++ans;
    }
};