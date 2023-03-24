class Solution {
private: 
    // we need (u, adj[u]) to store in ump 
    unordered_map<int, vector<int>> adj, back;
public:
    // DFS
    int minReorder(int n, vector<vector<int>>& connections) {
        // create adjacency list -- graph is directed
        for(vector<int>& v : connections) {
            adj[v[0]].push_back(v[1]); // node a->b -- outward edge 
            back[v[1]].push_back(v[0]); // node a<-b -- inward edge
        }
        
        int res = 0;
        vector<bool> visited(n);
        
        dfs(0, visited, res);
        
        return res;   
    }
    
    void dfs(int src, vector<bool> &visited, int &res) {
        visited[src] = true;
        
        for(int& v : adj[src]) {
            if(!visited[v]) {
                ++res,
                dfs(v, visited, res);
            }
        }
        
        for(int& v : back[src]) {
            if(!visited[v])
                dfs(v, visited, res);
        }
    }
    
};







