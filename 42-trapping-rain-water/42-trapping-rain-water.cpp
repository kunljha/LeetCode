class Solution {
public:
    int trap(vector<int>& arr) {
        int ans = 0;
        int maxleft = 0, maxright = 0;
        
        int l = 0, r = arr.size() - 1;
        
        while(l <= r) {
            if(arr[l] <= arr[r]) {
                if(arr[l] > maxleft)
                    maxleft = arr[l];
                else 
                    ans += maxleft - arr[l];
                
                ++l;
            } else {
                if(arr[r] > maxright) 
                    maxright = arr[r];
                else 
                    ans += maxright - arr[r];
                
                --r;
            }
        }
        
        return ans;
    }
};