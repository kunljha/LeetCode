class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        
        unordered_map<char, int> ump;
        for(char ch : s) ++ump[ch];
        
        vector<vector<char>> bucket(n+1); // freq lies in range [1...n]
        for(auto [ch, f] : ump)
            bucket[f].push_back(ch);
        
        string ans = "";
        for(int freq = n; freq >= 1; --freq) {
            for(auto ch : bucket[freq]) {
                ans.append(freq, ch);
            }
        }
        
        return ans;
    }
};