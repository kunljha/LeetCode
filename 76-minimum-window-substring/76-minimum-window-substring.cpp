class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        
        int ans = n;
        pair<int, int> p = {-1, -1};
        
        if(t.size() > s.size()) return "";
        
        unordered_map<char, int> mp;
        for(int i = 0; i < t.size(); ++i)
            ++mp[t[i]];
        
        int count = mp.size();
        
        int i = 0, j = 0;
        while(j < n) {
            
            while(j < n && count != 0) {
                if(mp.find(s[j]) != mp.end()) {
                    --mp[s[j]];
                    
                    if(mp[s[j]] == 0)
                        --count;
                }
                
                if(count == 0) break;
                
                ++j;
            }
            
            if(count == 0 && ans > j-i+1)
                ans = j-i+1;    
            
            while(count == 0) {
                if(mp.find(s[i]) != mp.end()) {
                    ++mp[s[i]];

                    if(mp[s[i]] == 1)
                        ++count; 
                }      

                if(ans >= j-i+1) {
                    ans = j-i+1;
                    p.first = i;
                    p.second = j;
                }
                
                ++i;
            }
            
            if(j == s.size()) break;
            
            ++j;
        }
        
        if(p.first == -1)
            return "";
        
        return s.substr(p.first, p.second - p.first + 1);
    }
};