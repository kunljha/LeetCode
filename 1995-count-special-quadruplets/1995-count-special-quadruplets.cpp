class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        
        unordered_map<int, int> hash;
        
        hash[nums[n-1]] = 1;
        
        for(int i = n-2; i >= 2; --i) {
            
            for(int j = i-1; j >= 1; --j) {
                
                for(int k = j-1; k >= 0; --k) {
                    
                    if(hash.count(nums[i] + nums[j] + nums[k]))
                        cnt += hash[nums[i] + nums[j] + nums[k]];
                }
            }
            
            ++hash[nums[i]];
        }

        return cnt;
    }
};