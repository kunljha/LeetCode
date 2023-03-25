class Solution {
private:
    long long total_nodes_vis = 0;  
    
public:
    // DFS
    long long countPairs(int n, vector<vector<int>>& edges) {
        // create adjacency list of graph
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(n);
        long long ans = 0;
        
        // first we count the no. of nodes in a connected component (say x)
        // DFS for a component will mark all the nodes of that component as visited
        // now those nodes that are still unvisited in graph after completion of DFS 
        // for that component, such nodes will be surely present in different connected component
        // so the no. of unreachable pairs for every node of that DFS traversed
        // component will be x*(unvisited_nodes)
        // unvisited_nodes = (n - total_nodes_vis)
        // above explanation gives ans for that single connected component
        // we need to find ans for all connected components that are there in graph
        // so ans = ans + x*(n - total_nodes_vis)
        
        for(int i = 0; i < n; ++i) {
            long long component_nodes = 0;
            
            if(!visited[i])
                dfs(i, component_nodes, adj, visited);
                
            ans += component_nodes * (n - total_nodes_vis);
        }
        
        return ans;    
    }
    
    void dfs(int src, long long &component_nodes, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[src] = true;
        ++component_nodes;
        ++total_nodes_vis;
        
        for(auto& v : adj[src]) {
            if(!visited[v])
                dfs(v, component_nodes, adj, visited);
        }  
    }
    
    
};







