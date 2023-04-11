class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        
        stack<char> st;
        
        for(int i = 0; i < n; ++i) {
            if(s[i] != '*') {
                st.push(s[i]);
            }
            else {
                st.pop();
            }
        }
        
        string res = "";
        while(not st.empty()) {
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;    
    }
};