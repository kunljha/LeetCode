class Solution {
public:
    int mySqrt(int x) {
        int ans = 0;
        int low = 1, high = x;
        
        while(low <= high) {
            long long mid = low + (high-low)/2;
            
            long long mSq = mid*mid;
            
            if(mSq == x) return mid;
            
            else if(x < mSq) high = mid-1;
            
            else {
                low = mid+1,
                ans = mid; 
            }    
        }
        
        return ans;
    }
};