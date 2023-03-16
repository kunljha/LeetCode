class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {     
        long long ans = 1;
        long long low = 1, high = (long long)totalTrips * (*min_element(time.begin(), time.end()));
        
        while(low <= high) {
            long long mid = low + (high-low)/2;
            
            if(check(mid, time, totalTrips)) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
    bool check(long long cur_time, vector<int> &time, int totalTrips) {
        long long trips_taken = 0;
        for(int i = 0; i < time.size(); ++i) {
            trips_taken += cur_time/time[i] ; 
        }
        
        return trips_taken >= totalTrips;
    }
};