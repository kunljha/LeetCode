class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> substring;
        
        func(0, s, substring, ans);
        
        return ans;
    }
    
    void func(int idx, string &s, vector<string> &partition, vector<vector<string>> &ans) {
        if(idx == s.size()) {
            ans.push_back(partition);
            return;
        }
        
        for(int i = idx; i < s.size(); ++i) {
            
            if(isPalindrome(idx, i, s)) {
                partition.push_back(s.substr(idx, i-idx+1));
                
                func(i+1, s, partition, ans);
                
                partition.pop_back();
            }
        }
    }
    
    bool isPalindrome(int start, int end, string s) {
        while(start <= end) {
            if(s[start] != s[end]) return false;
            
            ++start, --end;  
        }
        
        return true;
    }
};