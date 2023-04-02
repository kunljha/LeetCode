class Solution {
public:
    vector<int> successfulPairs(vector<int>& spell, vector<int>& potion, long long success) {
        int n = spell.size(), m = potion.size();
       
        sort(potion.begin(), potion.end());
        
        vector<int> ans(n);
        
        for(int i = 0; i < n; ++i) {
            int low = 0, high = m-1;
            
            while(low <= high) {
                int mid = low + (high - low)/2;
                
                long long s = spell[i], p = potion[mid];
                long long success_pair = s*p;
                
                if(success_pair >= success) {
                    ans[i] = m - mid;
                    high = mid - 1;
                }
                else 
                    low = mid + 1;
                
            }   
        }
        
        return ans;      
    }
    
};