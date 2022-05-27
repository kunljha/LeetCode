class Solution {
public:
    int numberOfSteps(int num) {
        int i = num;
        int steps = 0;
        
        while(i > 0) {
            if(i&1) {
                i -= 1;
                steps++;
            }
            else {
                i /= 2;
                steps++;
            }
        }
        
        return steps;
    }
};