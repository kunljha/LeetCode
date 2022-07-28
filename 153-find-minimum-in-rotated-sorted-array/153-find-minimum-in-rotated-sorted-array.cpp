class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        
        int low = 0, high = n-1;
        
        while(low <= high) {
            // to handle the corner-case when array may not be rotated at all
            if(nums[low] < nums[high]) {
                idx = low;
                break;
            }
            
            int mid = (low + high)/2;
            
            int next = (mid+1) % n;
            int prev = (mid+n-1) % n;
            
            if(nums[mid] <= nums[prev] && nums[mid] <= nums[next]) {
                idx = mid;
                break;
            }
            
            if(nums[low] <= nums[mid]) // i.e; left half is sorted
                low = mid+1;
            else
                high = mid-1; // i.e; right half is sorted
        }
        
        return nums[idx];
    }
};