class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        deque<int> q{1,2,3,4,5,6,7,8,9}; // all possible single digit nos.
        
        // run loop n-1 times since deque already contains nos. of one digit, we need remaining n-1 digits
        while(--n > 0) {
            int curSize = q.size();
            
            for(int i = 0; i < curSize; ++i) {
                int x = q.front(); // curr no.
                q.pop_front();
                
                // appending next possible digit by checking (abs diff from last_digit == k)
                for(int j = 0; j <= 9; ++j) {
                    if(abs(x % 10 - j) == k)
                        q.push_back(x * 10 + j);  
                }
            }
        }
        
        return vector<int> {q.begin(), q.end()};
    }
};