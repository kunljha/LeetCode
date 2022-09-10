class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> hash;
        
        long long curDay = 0;
        for(int &task : tasks) {  
            ++curDay;
            
            if(hash.count(task) && (curDay - hash[task]) <= space)
                curDay += space - (curDay - hash[task]) + 1;
            
            hash[task] = curDay;
        }
        
        return curDay;
    }
};