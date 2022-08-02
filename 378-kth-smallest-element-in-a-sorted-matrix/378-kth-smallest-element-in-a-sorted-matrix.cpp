class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); // since it is a square matrix
        
        priority_queue<int> maxHeap;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                maxHeap.push(matrix[i][j]);
                
                if(maxHeap.size() > k) 
                    maxHeap.pop();
            }
        }
        
        // end of loop, maxHeap will have k-smallest elements of matrix
        return maxHeap.top(); // gives kth smallest element
    }
};