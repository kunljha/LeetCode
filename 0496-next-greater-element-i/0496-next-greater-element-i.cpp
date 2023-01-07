class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& B, vector<int>& A) {
        unordered_map<int, int> ump;
        stack<int> st;
        
        int n = A.size();
        
        for(int i = n-1; i >= 0; --i) {
            if(st.empty()) {
                ump[A[i]] = -1;
            } 
            else if(st.top() > A[i]) {
                ump[A[i]] = st.top();
            }
            else {
                while(!st.empty() && st.top() <= A[i])
                    st.pop();
                
                if(st.empty()) ump[A[i]] = -1;
                else ump[A[i]] = st.top();
            }
            
            st.push(A[i]);
        }
        
        vector<int> ans; 
        for(int x : B) {
            ans.push_back(ump[x]);
        }
        
        return ans;
    }
};