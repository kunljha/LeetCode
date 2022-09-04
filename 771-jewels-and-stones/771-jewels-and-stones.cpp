class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int cnt = 0;
        
        unordered_set<char> hash(jewels.begin(), jewels.end());
        
        for (char s : stones)
            if (hash.count(s))
                ++cnt;
        
        return cnt;
    }
};