class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int maxProd = 0, currProd = 0;
        
        vector<bitset<26>> chars(n); // array of bitsets which will store bitset of every string from words-array
        
        for(int i = 0; i < n; i++) {
            for(char &ch: words[i]) {
                chars[i][ch - 'a'] = 1; // set the bit as 1 for characters that are present in string, i.e. words[i]
            }
            
            // checking all possible pair of strings, taking every pair from (0 to i-1) with i-th string
            for(int j = 0; j < i; j++) { 
                if(!isCommonPresent(chars[i], chars[j])) {
                    currProd = words[i].size() * words[j].size();
                    maxProd = max(currProd, maxProd);
                }  
            }
        }
        
        return maxProd;
    }
    
    bool isCommonPresent(bitset<26> &a, bitset<26> &b) {
    // traversing all bits of bitset to compares two string's bitset
        for(int i = 0; i < 26; i++) {
            if(a[i] && b[i]) return true;
        }
        
        return false;
    }
};