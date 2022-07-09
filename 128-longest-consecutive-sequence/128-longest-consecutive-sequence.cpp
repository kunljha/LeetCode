class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        unordered_set<int> hash(nums.begin(), nums.end());
        
        int res = 1;
        
        for(int &n : nums) {
            hash.erase(n); // res is already 1
            
            int prev = n-1, next = n+1;
            
            while(hash.count(prev)) hash.erase(prev--);
            while(hash.count(next)) hash.erase(next++);
            
            res = max(res, next-prev-1);
        }
        
        return res;     
    }
};