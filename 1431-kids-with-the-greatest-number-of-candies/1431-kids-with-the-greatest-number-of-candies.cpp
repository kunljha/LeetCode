class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int n = candies.size();
        
        int max_candies = 0;
        for(int i = 0; i < n; ++i) 
            max_candies = max(max_candies, candies[i]);
        
        vector<bool> res(n);
        for(int i = 0; i < n; ++i) {
            if(candies[i] + extra >= max_candies) {
                res[i] = true;
                // max_candies = candies[i] + extra;
            }
        }
        
        return res;
    }
};