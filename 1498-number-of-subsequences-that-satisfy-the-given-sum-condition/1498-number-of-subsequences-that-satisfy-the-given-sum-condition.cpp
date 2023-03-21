class Solution {
public:
    int numSubseq(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        
        int n = A.size();
        int mod = 1e9 + 7;
        int res = 0;
        
        vector<int> pow(n, 1);
        for(int i = 1; i < n; ++i) {
            pow[i] = (pow[i-1] * 2) % mod;
        }
        
        int l = 0, r = n-1;
        while(l <= r) {
            if(A[l] + A[r] <= target) {
                res = (res + pow[r - l]) % mod; // 2^(r-l)
                ++l;
            }
            else {
                --r;
            }
        }
        
        return res;
    }
};