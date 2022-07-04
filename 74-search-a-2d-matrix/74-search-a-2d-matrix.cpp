class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        
        int i = 0, j = n-1; // start from top-right corner
        
        while(i < m && j >= 0) {
            if(mat[i][j] > target)
                --j;
            else if(mat[i][j] < target)
                ++i;
            else return true;
        }
        
        return false;
    }
};