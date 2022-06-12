class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int idx = -1;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == nums[i+1]) {
                idx = i;
                break;
            }
        }
        
        return nums[idx];
    }
};