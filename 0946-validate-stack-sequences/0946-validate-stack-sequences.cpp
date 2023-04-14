class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), m = popped.size();
        
        stack<int> st;
        int i = 0, j = 0;
        while(i < n) {
            if(st.size() && popped[j] == st.top())
                st.pop(), ++j;
            else if(pushed[i] == popped[j])
                ++i, ++j;
            else st.push(pushed[i]), ++i;
        }
        
        while(j < m && st.size()) {
            if(popped[j] == st.top())
                st.pop(), ++j;
            else return false;
        }
        
        return true;   
    }
};