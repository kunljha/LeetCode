class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pascal(1, 1);
        
        for(int i = 1; i <= rowIndex; ++i) {
            pascal.resize(i+1);
            
            pascal[0] = 1, pascal[i] = 1;
            
            for(int j = i-1; j >= 1; --j)
                pascal[j] = pascal[j] + pascal[j-1];       
        }
        
        return pascal;
    }
};