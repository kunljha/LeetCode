class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        
        string s = "";
        int cnt = 1;
        int i = 1;    
        while(i < n) {
            if(chars[i] == chars[i-1]) {
                ++cnt;
            }
            else {
                s += chars[i-1];
                if(cnt > 1) s += to_string(cnt);
                cnt = 1;
            }  
            
            ++i;
        }
        
        s += chars[i-1];
        if(cnt > 1) s += to_string(cnt);
        
        chars.clear();
        for(char &ch : s) {
            chars.push_back(ch);
        }
        
        return chars.size();
        // cout << s << "\n";
        // return s.size();
    }
};