class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1) return n;
        
        int ans = 0, fib0 = 0, fib1 = 1;
        for(int i = 0; i < n-1; i++) 
           ans =  fib0 + fib1,
           fib0 = fib1, fib1 = ans;
        
        return ans;  
    }
};