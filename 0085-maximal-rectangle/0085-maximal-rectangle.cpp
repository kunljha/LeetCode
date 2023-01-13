class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans = 0;
        
        vector<int> v(m);
        for(int j = 0; j < m; ++j) {
            if(mat[0][j] == '1') v[j] = 1;
            else v[j] = 0;
        }
        
        ans = max(ans, largestRectangleArea(v));
        
        for(int i = 1; i < n; ++i) { 
            for(int j = 0; j < m; ++j) {
                if(mat[i][j] == '1') v[j] += 1;
                else v[j] = 0;
            }
            
            ans = max(ans, largestRectangleArea(v));   
        }
        
        return ans;    
    }
    
    int largestRectangleArea(vector<int>& H) {
        int n = H.size();
        vector<int> right = nearestSmallerToRight(H);
        vector<int> left = nearestSmallerToLeft(H);
        
        int max_area = 0;
        for(int i = 0; i < n; ++i) {
            int width = right[i] - left[i] -1;
            int area = H[i] * width;
            
            max_area = max(max_area, area);     
        }
        
        return max_area;    
    }
    
    vector<int> nearestSmallerToRight(vector<int> &A) {
        int n = A.size();
        stack<pair<int, int>> st;
        int psuedoInd = n;
        vector<int> right;
        
        for(int i = n-1; i >= 0; --i) {
            if(st.empty()) {
                right.push_back(psuedoInd);
            }
            else if(st.top().first < A[i]) {
                right.push_back(st.top().second);
            }
            else {
                while(!st.empty() && st.top().first >= A[i]) 
                    st.pop();
                
                if(st.empty()) right.push_back(psuedoInd);
                else right.push_back(st.top().second);
            }
            st.push({ A[i], i });
        }
        
        reverse(right.begin(), right.end());
        
        return right;
    }
    
    vector<int> nearestSmallerToLeft(vector<int> &A) {
        int n = A.size();
        stack<pair<int, int>> st;
        int psuedoInd = -1;
        vector<int> left;
        
        for(int i = 0; i < n; ++i) {
            if(st.empty()) {
                left.push_back(psuedoInd);
            }
            else if(st.top().first < A[i]) {
                left.push_back(st.top().second);
            }
            else {
                while(!st.empty() && st.top().first >= A[i]) 
                    st.pop();
                
                if(st.empty()) left.push_back(psuedoInd);
                else left.push_back(st.top().second);
            }
            st.push({ A[i], i });
        }
        
        return left;
    }
};