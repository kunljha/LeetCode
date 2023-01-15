class Solution {
public:
    int reverse(int x) {
        int sign = x < 0 ? -1 : 1;
        x = abs(x);
        int rev = 0;
        while (x > 0) {
            if (rev > INT_MAX / 10) return 0;
            rev = rev * 10 + x % 10;
            
            x /= 10;
        }
        
        return sign * rev;
    }
};