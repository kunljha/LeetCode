class Solution {
public:
    static bool myCmp(pair<int, char> &p1, pair<int, char> &p2) {
        return p1.first > p2.first;
    }
    
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> ump;
        
        for(int i = 0; i < n; ++i) {
            ++ump[s[i]];
        }
        
        vector<pair<int, char>> v;
        for(auto it = ump.begin(); it != ump.end(); ++it) {
            pair<int, char> p;
            p.first = it->second; // frequency
            p.second = it->first; // character
            
            v.push_back(p);
        }
        
        sort(v.begin(), v.end(), myCmp);
        
        string ans = "";
        for(auto p : v) { 
            int cnt = p.first;
            char ch = p.second;
            
            for(int i = 0; i < cnt; ++i)
                ans += ch;
        }
        
        return ans;
    }
};