class Solution {
public:
    void dfs(int u, vector<vector<int>> &adj, int &cnt, vector<bool> &visited) {
        visited[u] = true;
        ++cnt;
        
        for(auto v : adj[u]) {
            if(!visited[v])
                dfs(v, adj, cnt, visited);
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        // building tree
        vector<vector<int>> adj(n);
        
        for(int i = 0; i < edges.size(); ++i) { 
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visited(n, false);
        
        // marking restricted nodes as already visited
        for(int &v : restricted) {
            visited[v] = true;
        }
        
        int cnt = 0;
        dfs(0, adj, cnt, visited);
        
        return cnt;      
    }
};