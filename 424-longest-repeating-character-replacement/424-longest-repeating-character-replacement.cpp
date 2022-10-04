class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        vector<int> count(26, 0);
        
        int i = 0, j = 0;
        while(j < s.size()) { 
            ++count[s[j] - 'A'];
            
            // find most frequent char in window
            int most_freq = max(most_freq, count[s[j] - 'A']);
            
            // check if curr_window_size - most_freq <= k
            if((j-i+1) - most_freq <= k) {
                ans =  max(ans, j-i+1);
                ++j;
            } else {
                while((j-i+1) - most_freq > k) {
                    --count[s[i] - 'A'];

                    ++i;
                    
                    most_freq = *max_element(count.begin(), count.end());
                }

                ans =  max(ans, j-i+1);

                ++j;  
            }    
        }
        
        return ans;
    }
};