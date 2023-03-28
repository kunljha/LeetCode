class Solution {
public:
    // Tabulation
    int mincostTickets(vector<int>& day, vector<int>& cost) {
        int n = day.size();
        
        vector<int> dp(n+1, 0);
        
        // base-case
        dp[n] = 0;
        // 
        
        for(int i = n-1; i >= 0; --i) {
            // buy 1-day pass
            int cost_one = cost[0] + dp[i+1];

            // buy 7-day pass
            int j = i+1;
            for( ; j < n; ++j) {
                if(day[j] >= day[i] + 7) break;
            }
            int cost_seven = cost[1] + dp[j];

            // buy 30-day pass
            int k = i+1;
            for( ; k < n; ++k) {
                if(day[k] >= day[i] + 30) break;
            }
            int cost_thirty = cost[2] + dp[k];

            dp[i] = min(cost_one, min(cost_seven, cost_thirty)); 
        }
        
        return dp[0];
    }
    
    /*
    // Memoization
    int fun(int i, vector<int> &day, vector<int> &cost, vector<int> &dp) {
        int n = day.size();

        if(i == n) return 0;
        
        if(dp[i] != -1) return dp[i];

        // buy 1-day pass
        int cost_one = cost[0] + fun(i+1, day, cost, dp);

        // buy 7-day pass
        int j = i+1;
        for( ; j < n; ++j) {
            if(day[j] >= day[i] + 7) break;
        }
        int cost_seven = cost[1] + fun(j, day, cost, dp);  

        // buy 30-day pass
        int k = i+1;
        for( ; k < n; ++k) {
            if(day[k] >= day[i] + 30) break;
        }
        int cost_thirty = cost[2] + fun(k, day, cost, dp);

        return dp[i] = min(cost_one, min(cost_seven, cost_thirty));   
    }
    */
    
};