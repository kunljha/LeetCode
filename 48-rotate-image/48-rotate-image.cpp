class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        
        // taking tranpose of matrix
        for(int i = 0; i < rows; i++) 
            for(int j = i+1; j < cols; j++) 
                swap(mat[i][j], mat[j][i]);
        
        // reversing individual rows after tranpose
        for(int i = 0; i < rows; i++) {
            int low = 0, high = cols-1;
            
            while(low <= high) 
                swap(mat[i][low++], mat[i][high--]);
        }
    }
};