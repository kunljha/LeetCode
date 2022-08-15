class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == val) {
                int k = i+1;
                while(k < nums.size()) {
                    if(nums[k] != val) {
                        nums[i] = nums[k];
                        ++i;
                    }
                        
                    ++k;
                }
                
                nums.resize(i);
                break;
            }
        }
    
        return nums.size();
    }
};