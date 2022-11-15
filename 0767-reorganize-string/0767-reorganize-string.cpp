class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        
        // fill frequency array
        for(int i = 0; i < n; ++i)
            ++freq[s[i]-'a'];
        
        // find most occuring element
        int max = 0;
        int letter = -1;
        for(int i = 0; i < 26; ++i) {
            if(freq[i] > max) {
                max = freq[i];
                letter = i;
            }  
        }
        
        if(max > (n+1)/2) return "";
        
        vector<char> ans(n);
        
        // placing the 'letter' into ans char-array at 0,2,4..
        int ind = 0;
        while(freq[letter] > 0) {
            ans[ind] = (char)(letter+97);
            ind += 2;
            --freq[letter];
        }
        
        for(int i = 0; i < 26; ++i) {  
            while(freq[i] > 0) {
                if(ind >= n) ind = 1;

                ans[ind] = (char)(i+97);
                ind += 2;
                --freq[i];   
            }   
        }
        
        string str = "";
        for(char &ch : ans) {
            str += ch;
        }
        
        return str;
    }
};