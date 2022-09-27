class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size(), m = trainers.size();
        
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int cnt1 = 0, cnt2 = 0;
        
        int i = 0, j = 0;
        
        // alloting every player -> a trainer
        while(i < n && j < m) {
            if(trainers[j] >= players[i]) {
                ++cnt1;
                ++i, ++j;
            } else {
                ++j;
            }
        }
        
        i = 0, j = 0;
        
        // alloting every trainer -> a player
        while(i < n && j < m) {
            if(trainers[j] >= players[i]) {
                ++cnt2;
                ++i, ++j;
            } else {
                ++i;
            }
        }
        
        return max(cnt1, cnt2); 
    }
};