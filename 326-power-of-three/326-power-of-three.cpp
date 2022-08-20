class Solution {
public:
    bool isPowerOfThree(int n) {
        return func(n); 
    }
    
    bool func(int n) {
        if(n == 1) return true;
        
        if(n < 1) return false;
        
        return n % 3 == 0 ? func(n/3) : false;
    }
};