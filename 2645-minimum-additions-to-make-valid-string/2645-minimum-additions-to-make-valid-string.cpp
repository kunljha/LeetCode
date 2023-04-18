class Solution {
public:
    int addMinimum(string s) {
        int n = s.size();
        
        string t = "abc";
        int ans = 0;
        
        int i = 0, j = 0;
        while(i < n) {
            while(s[i] != t[j]) {
                ++ans;
                j = (j + 1)%3;
            }

            ++i;
            j = (j + 1)%3;      
        }
        
        if(s[i-1] == 'a') ans += 2;
        else if(s[i-1] == 'b') ans += 1;
        
        return ans;
    }
};