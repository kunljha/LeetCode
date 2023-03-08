class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = (int)1e9;
        int ans = 1;
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            
            if(canEat(piles, mid, h)) {
                ans = mid;
                high = mid-1; // search for smaller value of answer
            }
            else {
                low = mid+1;
            }       
        }
        
        return ans;
    }
    
    bool canEat(vector<int> &piles, int k, int h) {
        long totalHrs = 0;
        for(int &pile : piles) {
            totalHrs += ceil(pile*1.0 / k);
            
            // totalHrs += ceil((double)pile / k);
        }
        
        return totalHrs <= h;   
    }
};