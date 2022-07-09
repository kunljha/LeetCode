class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       int n = nums.size();
        
        if(n < 4) return {};
        
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++) {
            
            for(int j = i+1; j < n; j++) {
                
                long rem = (long)target - (long)(nums[i] + nums[j]);
                
                // applyling two pointer approach
                int left = j+1, right = n-1;
                
                while(left < right) {
                    if(nums[left] + nums[right] < rem) 
                        ++left;
                    else if(nums[left] + nums[right] > rem) 
                        --right;
                    else {
                        vector<int> quad(4, 0);
                        quad[0] = nums[i],
                        quad[1] = nums[j],
                        quad[2] = nums[left],
                        quad[3] = nums[right];
                        ans.push_back(quad);
                        
                        // skip duplicates
                        while(left < right && nums[left] == quad[2]) ++left;
                        while(left < right && nums[right] == quad[3]) --right;
                    }
                }
                
                while(j < n-1 && nums[j] == nums[j+1]) ++j;
            }
            
             while(i < n-1 && nums[i] == nums[i+1]) ++i;
        }
        
        return ans;
    }
};