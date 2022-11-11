class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        int i = n-1, minJump = 0;
        while(i >= 0) {
            if(nums[i] >= minJump)
                minJump = 0;      
           
            --i;
            
            if(i < 0) break; // it means entire array has been traversed
            
            ++minJump;
        }

        return minJump == 0;
    }
};