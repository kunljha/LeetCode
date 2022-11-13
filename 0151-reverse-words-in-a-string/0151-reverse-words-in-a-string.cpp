class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        
        n = removeSpaces(s, n);
        
        // to reverse the order of the words in string
        int start = 0;
        for(int end = 0; end < n; ++end) {
            if(s[end] == ' ') {
                reverse(s, start, end-1);
                start = end+1;
            }
        }
        
        reverse(s, start, n-1); // to reverse the last word remaining
        reverse(s, 0, n-1); // to reverse the whole string
        
        return s;
    }
    
    // to remove all redundant extra spaces
    int removeSpaces(string &s, int n) {
        int fill = 0, r = 0;
        
        while(r < n && s[r] == ' ') ++r; // to remove leading spaces
        
        while(fill < n) {
            while(r < n && s[r] != ' ') {
                s[fill] = s[r];
                ++fill;
                ++r;    
            }
            
            s[fill] = ' ';
            ++fill;
            
            while(r < n && s[r] == ' ') ++r;
            
            if(r == n) { 
                fill -= 2;
                s.resize(fill+1);
                break;
            }
        }
        
        return fill+1;
    }
    
    void reverse(string &s, int l, int r) {
        while(l < r)
            swap(s[l++], s[r--]);
    }
    
};