class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;
        
        
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end());
        
        vector<int> prev = intervals[0];
        
        for(int i = 1; i < intervals.size(); i++) {
            vector<int> curr = intervals[i];
            
            if(curr[0] <= prev[1]) // means intervals are overlapping
                prev[1] = max(curr[1], prev[1]);
            else    // when intervals don't overlap, push prev-interval in ans
                ans.push_back(prev),
                prev = curr;    
        }
        ans.push_back(prev);
        
        return ans;
    }
};