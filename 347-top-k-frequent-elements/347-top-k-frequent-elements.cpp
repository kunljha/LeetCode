class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        
        unordered_map<int, int> hash;
        for(int &num : nums)
            ++hash[num];
        
        
        priority_queue<pair<int, int>> maxH;
        
        for(auto it = hash.begin(); it != hash.end(); it++) {
            maxH.push(make_pair(it->second, it->first));
            
            if(maxH.size() > hash.size() - k) {
                ans.push_back(maxH.top().second);
                maxH.pop();
            }
        }
        
        return ans;
    }
};