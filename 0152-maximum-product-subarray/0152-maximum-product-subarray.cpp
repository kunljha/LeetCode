class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int runningMaxProd = 1, runningMinProd = 1;
        
        for(int x : nums) {
            if(x < 0) swap(runningMaxProd, runningMinProd);
            
            runningMaxProd = max(runningMaxProd*x, x);
            runningMinProd = min(runningMinProd*x, x);
            
            ans = max(ans, runningMaxProd);
        }
        
        return ans;
    }
};