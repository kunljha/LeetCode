class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        
        unordered_map<int, int> hash;
        
        for(int i = 0; i < B.size(); ++i)
            hash[B[i]] = i;
        
        for(int i = 0; i < A.size(); ++i) {
            int j = hash[A[i]];
            
            int k = j+1;
            for(  ; k < B.size(); ++k) {
                if(B[k] > B[j]) {
                    ans.push_back(B[k]); 
                    break;
                }
            }
            
            if(k == B.size()) {
                ans.push_back(-1); 
            }
        }
        
        return ans; 
    }
};