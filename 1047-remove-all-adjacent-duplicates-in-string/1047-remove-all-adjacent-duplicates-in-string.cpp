class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        string res = "";
        
        for(char &ch : s) {
            if(res.size() && ch == res.back())
                res.pop_back();
            else
                res.push_back(ch);
        }
        
        return res;
    }  
};