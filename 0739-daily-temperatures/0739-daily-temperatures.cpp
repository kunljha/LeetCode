class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        
        vector<int> ans;
        stack<pair<int, int>> st;
        for(int i = n-1; i >= 0; --i) {
            if(st.empty()) {
                ans.push_back(0);
            } else if(st.top().first > temps[i]) {
                ans.push_back(st.top().second - i);
            } else {
                while(not st.empty() && st.top().first <= temps[i])
                    st.pop();
                
                ans.push_back(st.empty() ? 0 : st.top().second - i);
            }
            
            st.push({ temps[i], i });
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};