class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& A, vector<vector<int>>& B) {
        map<int, int> mp;
        
        for(int i = 0; i < A.size(); ++i)
            mp[A[i][0]] = A[i][1];
        
        for(int i = 0; i < B.size(); ++i)
            mp[B[i][0]] += B[i][1];
        
        vector<vector<int>> ans;
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            ans.push_back({ it->first, it->second });
        }
        
        return ans;   
    }
};