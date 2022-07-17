class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxH;
        
        for(int i = 0; i < points.size(); ++i) {
            vector<int> point = points[i];
            
            int dist = point[0]*point[0] + point[1]*point[1];
            
            maxH.push(make_pair(dist, make_pair(point[0], point[1])));
            
            if(maxH.size() > k)
                maxH.pop();
        }
        
        vector<vector<int>> ans;
        
        while(!maxH.empty()) {
            vector<int> point(2);
            
            point[0] = maxH.top().second.first;
            point[1] = maxH.top().second.second;
            
            ans.push_back(point);
            
            maxH.pop();
        }
        
        return ans;   
    }
};