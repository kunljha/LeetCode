class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int minVal = INT_MAX;
         int profit = 0, currProfit = 0;
        
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < minVal) {
                minVal = prices[i];
            }
                 
            currProfit = prices[i] - minVal;
            profit = max(profit, currProfit);
        }
            
        return profit;   
    }
};