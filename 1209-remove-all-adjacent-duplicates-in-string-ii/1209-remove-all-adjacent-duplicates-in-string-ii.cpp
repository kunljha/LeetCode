class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        
        stack<pair<char, int>> st;
        for(int j = 0; j < n; ++j) {
            if(st.empty()) {
                st.push({ s[j], 1 });
            }
            else {
                if(st.top().first == s[j]) {
                    ++st.top().second;
                    
                    if(st.top().second == k) st.pop();
                }
                else {
                    st.push({ s[j], 1 });
                }
            }
        }
        
        s = "";
        while(not st.empty()) {
            s += string(st.top().second, st.top().first);
            st.pop();
        }
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};