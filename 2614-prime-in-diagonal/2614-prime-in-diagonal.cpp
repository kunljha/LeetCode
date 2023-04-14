class Solution {
public:
    int diagonalPrime(vector<vector<int>>& a) {
        int n = a.size();
        int res = 0;
        
        for(int i = 0; i < n; ++i) {
            if(isPrime(a[i][i]))
                res = max(res, a[i][i]);
            
            if(isPrime(a[i][n-1-i])) 
                res = max(res, a[i][n-1-i]);
            
        }
        
        return res;    
    }
    
    bool isPrime(int x) {
        if(x == 1) return false;

        for (int i = 2; i*i <= x; ++i)
            if(x % i == 0) return false;

        return true;
    }
    
};