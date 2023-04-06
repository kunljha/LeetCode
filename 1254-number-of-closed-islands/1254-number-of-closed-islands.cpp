class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] == 0 && dfs(i, j, grid))
                    ++res;
            
        
        return res;
    }
    
    bool dfs(int i, int j, vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        
        if(i < 0 || i == n || j < 0 || j == m)
            return false;
        
        if(grid[i][j] == 1)
            return true;
        
        grid[i][j] = 1;
        
        /* return dfs(i, j+1, grid) && dfs(i, j-1, grid) && dfs(i+1, j, grid) && dfs(i-1, j, grid);
        We cannot return like above because if any of the first dfs() returns false then following ones
        will not execute. Then we cannot mark the 0s in those dfs calls to 1s
        */
        
        bool d1 = dfs(i, j+1, grid);
        bool d2 = dfs(i, j-1, grid);
        bool d3 = dfs(i+1, j, grid);
        bool d4 = dfs(i-1, j, grid);
        
        return d1 && d2 && d3 && d4;
    }
    
};