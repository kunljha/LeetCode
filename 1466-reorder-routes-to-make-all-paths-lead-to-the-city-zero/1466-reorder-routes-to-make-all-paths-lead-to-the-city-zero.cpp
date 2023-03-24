class Solution {
public:
    // BFS
    int minReorder(int n, vector<vector<int>>& connections) {
        // create adjacency list -- graph is directed
        vector<vector<int>> adj(n), back(n);
        for(vector<int>& v : connections) {
            adj[v[0]].push_back(v[1]); // node a->b -- outward edge 
            back[v[1]].push_back(v[0]); // node a<-b -- inward edge
        }
        
        int res = 0;
        vector<bool> visited(n);
        queue<int> q;
        q.push(0);
        
        while(not q.empty()) {
            int u = q.front();
            q.pop();
            
            visited[u] = true;
            
            for(int& v : adj[u]) {
                if(!visited[v]) {
                    // v-node is not visited and edge is facing outward from u to v,
                    // we need to reorder this edge inward so increment res
                    // pushing v-node in queue bcoz maybe its adjacent node's are 
                    // also connected by outward edge to v
                    ++res; 
                    q.push(v);
                }
            }
            
            for(int& v : back[u]) {
                if(!visited[v])
                // v-node is not visited and edge is facing inward from u to v,
                // so no need to reorder this already inward edge
                // pushing v-node in queue bcoz maybe its adjacent node's are 
                // connected by outward edge to v
                q.push(v);    
            }      
            
        }
        
        return res;     
    }
};