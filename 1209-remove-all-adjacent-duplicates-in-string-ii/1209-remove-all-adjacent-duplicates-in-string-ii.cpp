class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        
        int i = 0;
        for(int j = 0; j < n; ++j) {
            s[i] = s[j];
            
            if(i-k+1 >= 0) {
                int l = i-k+1;
                for( ; l < i; ++l) {
                    if(s[l] == s[i]) continue;
                    else break;
                }

                if(l == i) i = i-k;
            }
            
            ++i;
        }
        
        return s.substr(0, i);
    }
};