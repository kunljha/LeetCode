class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = s.size(), m = removable.size();
        
        int ans = 0;
        int low = 0, high = m;
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(check(mid, s, p, removable)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return ans;     
    }
    
    bool check(int k, string s, string p, vector<int> removable) {
        for(int i = 0; i < k; ++i)
            s[removable[i]] = '*';
        
        string temp = "";
        for(int i = 0; i < s.size(); ++i)
            if(s[i] != '*') 
                temp += s[i];
        
        
        return isSubseq(temp, p);    
    }
    
    bool isSubseq(string a, string b) {
        int n = a.size(), m = b.size();
        
        int i = n-1, j = m-1;
        while(i >= 0 && j >= 0) {
            if(a[i] == b[j])
                --j;
            
             --i;   
        }
        
        return (j < 0);
    }
    
};