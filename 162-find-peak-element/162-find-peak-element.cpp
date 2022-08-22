class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return 0; 
        
        int low = 0, high = n-1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            
            // check first element for peak
            if(mid == 0 && nums[0] > nums[1])
                return 0;
            
            // check last element for peak
            if(mid == n-1 && nums[n-1] > nums[n-2])
                return n-1;
            
            // binary search
            if(mid-1 >= 0 && mid+1 <= n-1 && nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            
            else if(mid-1 >= 0 && nums[mid-1] > nums[mid]) 
                high = mid-1;
            
            else if(mid+1 <= n-1 && nums[mid+1] > nums[mid])
                low = mid+1;
            
        }
        
        return -1;
    }
};