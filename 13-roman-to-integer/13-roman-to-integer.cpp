class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hash;
        
        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;
        
        if(s.size() == 1) return hash[s[0]];
        
        int curInt = 0, prevInt = 0, sum = 0;
        for(int i = s.size() - 1; i >= 0; --i) {
            curInt = hash[s[i]];
            
            if(curInt >= prevInt)
                sum += curInt;
            else
                sum -= curInt;
            
            prevInt = curInt;
        }
        
        return sum;
    }
};