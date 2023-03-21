class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        
        int l = 0, r = height.size()-1;
        while(l < r) {
            int water = (r - l) * min(height[l], height[r]);
            
            max_water = max(max_water, water);
            
            if(height[l] < height[r])
                ++l;
            else if(height[r] < height[l])
                --r;
            else
                ++l, --r;     
        }
        
        return max_water;
    }
};