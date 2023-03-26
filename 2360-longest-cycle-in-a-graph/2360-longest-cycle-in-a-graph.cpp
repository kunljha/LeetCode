class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        
        // gives WA to create adjacency list of directed graph this way 
        
        // vector<int> adj(n);
        // for(int i = 0; i < n; ++i) {
        //     if(edges[i] != -1)
        //         adj[i] = edges[i];
        // }
        
        // bcoz consider a case if edges[i] == -1 then
        // adj[i] will not be assigned as edges[i]
        // so adj[i] will remain at its default value, i.e; 0
        // but adj[i] = 0 will mean that there is a directed edge from i->0 which is not necessarily true
        
        
        // problem statement says : "The graph is represented with a given 0-indexed array edges of size n"
        // so use edges itself as graph representation
        
        vector<int> timeVisited(n); // to store time at which each node is visited first time
        int ans = -1; // if no cycle exists we need to return -1
        int t = 1; // initially, time t = 1
        
        for(int i = 0; i < n; ++i) {
            if(timeVisited[i] > 0) continue; // if the node is already visited, skip it
            
            int start_time = t; // record the start time of the current traversal
            int u = i;
            // traverse the graph until the end of the path is reached or a visited node is encountered
            while(u != -1 && timeVisited[u] == 0) {
                timeVisited[u] = t++;
                u = edges[u];
            }

            if(u != -1 && timeVisited[u] >= start_time)
                ans = max(ans, t - timeVisited[u]);
                        
        }
        
        return ans;              
    }     
};
