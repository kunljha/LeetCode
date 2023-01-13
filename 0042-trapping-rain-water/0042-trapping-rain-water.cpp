class Solution {
public:
    int trap(vector<int>& H) {
        // idea: water trapped at index i = min(lmax[i], rmax[i]) - current height
        
        int n = H.size();
        
        vector<int> lmax(n);
        lmax[0] = H[0];
        for(int i = 1; i < n; ++i) {
            lmax[i] = max(lmax[i-1], H[i]);
        }
        
        vector<int> rmax(n);
        rmax[n-1] = H[n-1];
        for(int i = n-2; i >= 0; --i) {
            rmax[i] = max(rmax[i+1], H[i]);
        }
        
        int total = 0;
        for(int i = 0; i < n; ++i) {
            total += min(lmax[i], rmax[i]) - H[i];
        }
        
        return total;
    }
};