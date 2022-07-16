class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        
        unordered_map<int, int> hash;
        for(int &num : nums)
            ++hash[num];
        
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        
        for(auto it = hash.begin(); it != hash.end(); it++) {
            minH.push(make_pair(it->second, it->first));
            
            if(minH.size() > k)
                minH.pop();    
        }
        
        while(k--) {
            ans.push_back(minH.top().second);
            minH.pop();
        }
        
        return ans;
    }
};