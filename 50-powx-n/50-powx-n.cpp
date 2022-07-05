class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long pow = n; // to handle overflow
        
        if(n < 0) pow = -1.0*n;
        
        while(pow > 0) {
            if(pow%2 == 0) {
                x = x*x;
                pow /= 2;
            } else {
                ans = ans*x;
                pow -= 1;
            }
        }
        
        if(n < 0) 
            ans = 1.0/ans;
        
        return ans;
    }
};