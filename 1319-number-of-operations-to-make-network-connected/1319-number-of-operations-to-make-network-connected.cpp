class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        
        vector<vector<int>> adj(n);
        for(auto& v : connections) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector<bool> visited(n, false);
        
        int components = 0;
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                ++components;
                dfs(i, adj, visited);
            }
        }
        
        return components - 1;      
    }
    
    void dfs(int src, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[src] = true;
        
        for(int& v : adj[src]) {
            if(!visited[v])
                dfs(v, adj, visited);
        }
        
    }
    
};





