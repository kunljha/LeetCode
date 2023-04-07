class Solution {
public:
    // BFS
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 1) {
                    q.push({ i, j });
                    visited[i][j] = true;
                }
            }
        }
        
        while(not q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            // all four directions
            if(i > 0 && grid[i-1][j] == 1 && !visited[i-1][j]) {
                q.push({ i-1, j });
                visited[i-1][j] = true;   
            }
            
            if(i+1 < m && grid[i+1][j] == 1 && !visited[i+1][j]) {
                q.push({ i+1, j });
                visited[i+1][j] = true;  
            }
            
            if(j > 0 && grid[i][j-1] == 1 && !visited[i][j-1]) {
                q.push({ i, j-1 });
                visited[i][j-1] = true; 
            }
            
            if(j+1 < n && grid[i][j+1] == 1 && !visited[i][j+1]) {
                q.push({ i, j+1 });
                visited[i][j+1] = true;
            }
             
        }
        
        int res = 0;
        for(int i = 0; i < m; ++i) 
            for(int j = 0; j < n; ++j) 
                if(grid[i][j] == 1 && !visited[i][j]) 
                    ++res;
        
        return res;
    }
    
    // idea taken from : https://leetcode.com/problems/number-of-enclaves/discuss/3389104/Day-97-oror-BFS-oror-Easiest-Beginner-Friendly-Sol
};