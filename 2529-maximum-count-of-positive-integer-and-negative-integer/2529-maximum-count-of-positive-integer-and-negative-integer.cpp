class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
    
        // find index of first occurence of positive integer
        int first_ind_pos = -1;
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] > 0) {
                first_ind_pos = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        int cnt_pos = 0;
        if(first_ind_pos > -1)
            cnt_pos = (n-1) - first_ind_pos + 1;
        
        
        // find index of last occurence of negative integer
        int last_ind_neg = -1;
        low = 0, high = n-1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] < 0) {
                last_ind_neg = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        int cnt_neg = 0;
        if(last_ind_neg > -1)
            cnt_neg = last_ind_neg - 0 + 1;
        
        return max(cnt_pos, cnt_neg);    
    }
};