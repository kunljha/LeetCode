class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int x = 1, i = 0;
        
        while(i < arr.size()) {
            if(x == arr[i]) 
                ++i;
            else if(--k == 0)
                return x;
            
            ++x;
        }
        
        return x + (k-1);
    }
};