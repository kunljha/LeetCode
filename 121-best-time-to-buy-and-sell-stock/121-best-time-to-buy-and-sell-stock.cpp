class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0, curP = 0;
        
        int l = 0, r = 1; // left = day to buy, right = day to sell
        
        while(r < prices.size()) {
            if(prices[r] > prices[l])
                curP = prices[r] - prices[l];
            else
                l = r;     
            
            ++r;
            maxP = max(maxP, curP);
        }
        
        return maxP;
    }
};