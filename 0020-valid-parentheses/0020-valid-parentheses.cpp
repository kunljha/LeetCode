class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char ch : s) {
            if(ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if(st.empty() || not isMatch(st.top(), ch)) return false;
                
                st.pop();     
            }
        }
        
        return st.empty();
    }
    
    bool isMatch(char a, char b) {
        return a == '(' && b == ')' or
            a == '{' && b == '}' or
            a == '[' && b == ']' ; 
    }
};