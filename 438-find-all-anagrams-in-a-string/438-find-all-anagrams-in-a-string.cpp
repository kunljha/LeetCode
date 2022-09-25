class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), k = p.size();
        
        unordered_map<char, int> hash;
        for(int i = 0; i < k; ++i)
            ++hash[p[i]];
        
        int count = hash.size();
        
        vector<int> ans;
        
        int i = 0, j = 0;
        while(j < n) {
            if(hash.find(s[j]) != hash.end()) {
                --hash[s[j]];
                
                if(hash[s[j]] == 0)
                    --count;
            }
            
            if(j-i+1 < k) {
                ++j;
            } else {
                if(count == 0) {
                    ans.push_back(i);
                }
                
                if(hash.find(s[i]) != hash.end()) {
                    ++hash[s[i]];
                    
                    if(hash[s[i]] == 1)
                        ++count;
                }
                
                ++i, ++j;  
            }
        }
        
        return ans;
        
    }
};