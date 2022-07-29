class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int fpos = -1, lpos = -1;
            
        int low = 0, high = nums.size()-1;
        
        
        // find out first occurence
        while(low <= high) {
            int mid = (low + high)/2;
            
            if(target == nums[mid])
                fpos = mid,
                high = mid-1;
            else if(target < nums[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        
        // reset low & high to find last occurence
        low = 0, high = nums.size()-1;
        
        while(low <= high) {
            int mid = (low + high)/2;
            
            if(target == nums[mid]) 
                lpos = mid,
                low = mid+1;
            else if(target < nums[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        
        return {fpos, lpos};  
    }
    
};