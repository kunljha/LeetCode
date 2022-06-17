class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
            int m = a.size(), n = a[0].size();
            bool isCol0 = false;
            bool isRow0 = false;
            
            for (int i = 0; i < m; i++) { // checking 0th column for any element i.e 0
                if (a[i][0] == 0) {
                    isCol0 = true;
                    break;
                } 
            }
        
            for (int j = 0; j < n; j++) { // checking 0th row for any element i.e 0
                if (a[0][j] == 0) {
                    isRow0 = true;
                    break;
                } 
            }
        
            // traversing matrix from index-1-row & index-1-column
            for (int i = 1; i < m; i++) { 
                for (int j = 1; j < n; j++) {
                    if (a[i][j] == 0) {
                        a[i][0] = 0; // set 0th element of ith row to zero
                        a[0][j] = 0; // set 0th element of jth column to zero
                    }
                }     
            }
        
            for (int i = 1; i < m; i++) { 
               for (int j = 1; j < n; j++) 
                   if (a[i][0] == 0 || a[0][j] == 0)
                       a[i][j] = 0;
            }  
        
            if (isCol0) { // setting zeroth column elements to zero
                for (int i = 0; i < m; i++) 
                    a[i][0] = 0;
            }
        
            if (isRow0) { // setting zeroth row elements to zero
                for (int j = 0; j < n; j++) 
                    a[0][j] = 0;
            }
    }
};