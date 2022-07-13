class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        
        int ans = 0;
        
        // prefix array to store max on left of arr[i]
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];
        
        for(int i = 1; i < n; i++)
            prefix[i] = max(arr[i], prefix[i-1]);
        
        // suffix array to store max on right of arr[i]
        vector<int> suffix(n, 0);
        suffix[n-1] = arr[n-1];
        
        for(int i = n-2; i >= 0; i--)
            suffix[i] = max(arr[i], suffix[i+1]);
        
        // units of water trapped
        for(int i = 0; i < n; i++) 
            ans += min(prefix[i], suffix[i]) - arr[i];
        
        return ans;
    }
};