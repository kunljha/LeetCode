class Solution {
public:
    bool canReach(vector<int>& arr, int start) {    
        if(arr[start] == 0) return true;
        
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        
        q.push(start);
        visited[start] = true;
        while(not q.empty()) {
            int size = q.size();
            
            while(size--) {
                int cur_ind = q.front();
                q.pop();
                
                if(arr[cur_ind] == 0) return true;
                
                if(cur_ind + arr[cur_ind] < n && !visited[cur_ind + arr[cur_ind]]) {
                    q.push(cur_ind + arr[cur_ind]),
                    visited[cur_ind + arr[cur_ind]] = true;
                }
                
                if(cur_ind - arr[cur_ind] >= 0 && !visited[cur_ind - arr[cur_ind]]) {
                    q.push(cur_ind - arr[cur_ind]),
                    visited[cur_ind - arr[cur_ind]] = true;
                }
                
            }
            
        }
        
        return false;
    }
};