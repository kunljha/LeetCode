class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        for(auto& s: strs) {
            string temp = sort(s);
            
            ump[temp].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto& it : ump) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
    
    string sort(string s) {
        vector<int> count(26, 0);
        
        for(char& ch: s) {
            ++count[ch-'a'];
        }
        
        string temp = "";
        for(int i = 0; i < 26; ++i) {
            temp += string(count[i], i + 'a');
        }
        
        return temp;
    }
};