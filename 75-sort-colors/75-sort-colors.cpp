class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cntZeros = 0, cntOnes = 0, cntTwos = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) cntZeros++;
            else if(nums[i] == 1) cntOnes++;
            else if(nums[i] == 2) cntTwos++;
        }
        
        for(int i = 0; i < cntZeros; i++) nums[i] = 0;
        for(int i = cntZeros; i < cntZeros+cntOnes; i++) nums[i] = 1;
        for(int i = cntZeros+cntOnes; i < nums.size(); i++) nums[i] = 2;
    }
};