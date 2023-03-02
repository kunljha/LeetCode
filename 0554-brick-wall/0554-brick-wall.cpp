class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        unordered_map<int, int> edgeFreq; // (brick_edge_index, count)
        int maxEdges = 0;
        
        for(int i = 0; i < wall.size(); ++i) {
            int idx = 0;
            
            for(int j = 0; j < wall[i].size() - 1; ++j) {
                idx += wall[i][j];
                
                ++edgeFreq[idx];
                maxEdges = max(maxEdges, edgeFreq[idx]);   
            }
        }
        
        return wall.size() - maxEdges; 
    }
};