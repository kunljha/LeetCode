class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
            while(low <= high)
            {
                int mid = low + (high - low)/2;
                int comparator = nums[mid];
                
                if(target < nums[0] == nums[mid] < nums[0]) // if nums[mid] & target are on same side
                    comparator = nums[mid];
                else
                    comparator = target < nums[0] ? INT_MIN : INT_MAX; // nums[mid] & target are on different side 
                
                
                if(target == comparator) return mid;
                
                if(target > comparator)            
                    low = mid+1;            
                else
                    high = mid-1;
            }
            return -1;
    }
};