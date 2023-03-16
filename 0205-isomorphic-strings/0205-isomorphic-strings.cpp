class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        vector<int> mps(256, -1), mpt(256, -1);
        
        for(int i = 0; i < n; ++i) {
            if(mps[s[i]] != mpt[t[i]]) return false;
            
            mps[s[i]] = i;
            mpt[t[i]] = i;
        }
        
        return true;
    }
};