class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        
        int last_given = 0;
        
        for(int i = 0; candies > 0; i = (i+1) % num_people) {
            if(candies <= last_given+1) {
                ans[i] += candies;
                break;
            } else {
                ans[i] += last_given + 1;
                ++last_given;
                candies -= last_given;
            }
        }
        
        return ans;
    }
};