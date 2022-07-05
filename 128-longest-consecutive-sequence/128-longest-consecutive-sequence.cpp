class Solution {
public:
    int longestConsecutive(vector<int>& num) {
        if(num.size() == 0) return 0;
        
        unordered_set<int> hash(num.begin(), num.end());
        
        int res = 1;
        
        for(int &n : num) {
            hash.erase(n);
            
            int prev = n-1, next = n+1;
            
            while(hash.find(prev) != hash.end()) hash.erase(prev--);
            while(hash.find(next) != hash.end()) hash.erase(next++);
            
            res = max(res, next-prev-1);
        }
        
        return res;     
    }
};