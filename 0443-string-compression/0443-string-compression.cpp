class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        
        int i = 0, j = 0;
        int fill = 0;
        while(j < n) {
            int cnt = 0;
            
            while(j < n && chars[j] == chars[i]) {
                ++cnt, 
                ++j;
            }
            
            chars[fill++] = chars[i];
            if(cnt > 1) {
                string str = to_string(cnt);
                
                for(char &ch : str)
                    chars[fill++] = ch;
                
            }
            
            i = j;     
        }
        
        return fill;
    }
};