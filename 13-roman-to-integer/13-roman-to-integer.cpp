class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hash1;
        
        hash1['I'] = 1;
        hash1['V'] = 5;
        hash1['X'] = 10;
        hash1['L'] = 50;
        hash1['C'] = 100;
        hash1['D'] = 500;
        hash1['M'] = 1000;
        
        // for substraction cases
        unordered_map<string, int> hash2;
        
        hash2["IV"] = 4;
        hash2["IX"] = 9;
        hash2["XL"] = 40;
        hash2["XC"] = 90;
        hash2["CD"] = 400;
        hash2["CM"] = 900;
        
        if(s.size() == 1) return hash1[s[0]];
        
        string key = "";
        int i = 0, sum = 0;
        for(i = 0; i < s.size() - 1; ++i) {
            key = s.substr(i, 2);
            if(hash2.count(key)) {
                sum += hash2[key];
                ++i;
            } else {
                sum += hash1[s[i]];
            }
        }
        
        key = s.substr(i-1, 2);
        if(not hash2.count(key)) 
            sum += hash1[s[i]];
        
        return sum;
    }
};