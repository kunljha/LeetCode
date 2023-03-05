class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        if(n == 1) return 0;
        
        unordered_map<int, vector<int>> ump; // (arr[i], indices where arr[i] is present)
        for(int i = 0; i < n; ++i) {
            ump[arr[i]].push_back(i);
        }
        
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        int steps = 0;
        
        while(not q.empty()) {
            int size = q.size();
            
            while(size--) {
                int cur_ind = q.front();
                q.pop();
                
                if(cur_ind == n-1) return steps;
                
                vector<int>& nextIndicesToJump = ump[arr[cur_ind]];
                nextIndicesToJump.push_back(cur_ind - 1);
                nextIndicesToJump.push_back(cur_ind + 1);
                
                for(int& next_ind : nextIndicesToJump) {
                    if(next_ind >= 0 && next_ind < n && !visited[next_ind]) {
                        q.push(next_ind);
                        visited[next_ind] = true;
                    }
                }
                
                nextIndicesToJump.clear();          
            }
            
            ++steps;
        }
        
        return steps;       
    }
};