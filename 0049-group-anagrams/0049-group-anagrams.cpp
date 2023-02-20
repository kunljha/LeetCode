class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        for(string s: strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            ump[temp].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto it: ump) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};