class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int low = i+1;
            int high = nums.size() - 1;
            
            while(low < high) {
                int sum = nums[low] + nums[high];
                
                if(sum < target) low++;
                
                else if(sum > target) high--;
                
                else {
                    vector<int> triplet = {nums[i], nums[low], nums[high]};
                    ans.push_back(triplet);
                    
                    // to skip duplicates
                    while(low < high && nums[low] == triplet[1]) low++;
                    
                    while(low < high && nums[high] == triplet[2]) high--;
                }
            }
            
            while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
        
        return ans; 
    }
};