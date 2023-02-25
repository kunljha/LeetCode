class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        ump[0] = 1;
        int sum = 0, ans = 0;
        for(int &x : nums) {
            sum += x;
            
            int rem = (sum % k + k) % k;
            
            if(ump.count(rem)) {
                ans += ump[rem];
            }
            
            ++ump[rem];
        }
        
        return ans;
    }
};