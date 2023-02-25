class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> ump;
        for(char &t : tasks) {
            ++ump[t];
        }
        
        priority_queue<int> maxHeap;
        for(auto &it : ump) {
            maxHeap.push(it.second);
        }
        
        queue<pair<int, int>> q;
        int time = 0;
        while(maxHeap.size() || q.size()) {
            ++time;
            if(maxHeap.size()) {
                int freq = maxHeap.top();
                maxHeap.pop();
                --freq;

                if(freq > 0) q.push({ freq, time+n });
            }
           
            if(q.size() && time == q.front().second) {
                maxHeap.push(q.front().first);
                q.pop();
            }    
        }
        
        return time;    
    }
};