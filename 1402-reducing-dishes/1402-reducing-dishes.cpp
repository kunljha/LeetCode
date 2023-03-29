class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        int n = satisfaction.size(), ans = 0, preSum = 0, timeCoefficient = 0;
        for (int i = n-1; i >= 0; i--) {
            if (preSum + satisfaction[i] <= 0) {
                break;
            }
            preSum += satisfaction[i];
            timeCoefficient += preSum;
            ans = max(ans, timeCoefficient);
        }
        return ans;
    }
};