class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++) {
            int two_sum = -nums[i];
            
            // applying two pointer approach
            int low = i+1, high = n - 1;
            
            while(low < high) {
                if(nums[low] + nums[high] < two_sum) ++low;
                
                else if(nums[low] + nums[high] > two_sum) --high;
                
                else {
                    vector<int> triplet = {nums[i], nums[low], nums[high]};
                    ans.push_back(triplet);
                    
                    // to skip duplicates
                    while(low < high && nums[low] == triplet[1]) ++low;
                    
                    while(low < high && nums[high] == triplet[2]) --high;
                }
            }
            
            while(i < n-1 && nums[i] == nums[i+1]) ++i;
        }
        
        return ans; 
    }
};