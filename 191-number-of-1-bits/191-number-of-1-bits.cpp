class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n > 0)
        {
           n = n&(n-1); // un-sets the rightmost setbit of n
           cnt++;
        }   
        return cnt;
    }
};