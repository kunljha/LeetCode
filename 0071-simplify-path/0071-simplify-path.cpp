class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        
        for(int i = 0; i < path.size(); ++i) {
            if(path[i] == '/') continue;
            
            string temp = "";
            while(i < path.size() && path[i] != '/') {
                temp += path[i];
                ++i;
            }
            if(temp == ".") continue;
            else if(temp == "..") {
                if(st.size())
                    st.pop();
            }
            else st.push(temp);
            
        }
        
        string res = "";
        while(st.size()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        
        if(res.size() == 0) return "/";
        
        return res;
    }
    
    // approach : https://leetcode.com/problems/simplify-path/discuss/1847357/C%2B%2B-oror-Easy-oror-Stack-oror-Simple-oror-Explained-oror-Algorithm
};