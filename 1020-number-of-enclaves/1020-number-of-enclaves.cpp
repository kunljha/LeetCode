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
        
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(not q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            // all four directions
            for(auto& [dx, dy] : dirs) {
                int i = x + dx;
                int j = y + dy;
                
                if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1 && !visited[i][j]) {
                    q.push({ i, j });
                    visited[i][j] = true;
                }
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