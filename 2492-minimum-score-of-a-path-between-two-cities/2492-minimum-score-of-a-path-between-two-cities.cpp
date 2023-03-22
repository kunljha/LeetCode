class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        
        // create adjacency list
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto& r : roads) {
            adj[r[0]].push_back({ r[1], r[2] });
            adj[r[1]].push_back({ r[0], r[2] });
        }
        
        vector<bool> visited(n+1);
        queue<int> q;
        q.push(1), visited[1] = true;
        while(not q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto& [v, dist] : adj[node]) {
                ans = min(ans, dist);
                
                if(!visited[v]) {
                    q.push(v),
                    visited[v] = true;
                }   
            }
            
        }
        
        return ans;     
    }
};