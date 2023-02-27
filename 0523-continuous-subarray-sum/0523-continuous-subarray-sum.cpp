class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> ump;
        ump[0] = -1;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            
            int rem = sum % k;
            
            if(ump.count(rem) && i - ump[rem] >= 2)
                return true; 
            
            if(!ump.count(rem))
                ump[rem] = i;  
        }
        
        return false;     
    }
};