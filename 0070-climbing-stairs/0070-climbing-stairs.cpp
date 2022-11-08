class Solution {
public:
    int climbStairs(int n) { 
        int prev2 = 0, prev = 1;
        
        for(int step = 1; step <= n; ++step) {
            int oneStep = prev;
            int twoStep = 0;
            if(step > 1) 
                twoStep = prev2;

            int cur = oneStep + twoStep;
            
            prev2 = prev;
            prev = cur;
        }
        
        return prev;
    }
};