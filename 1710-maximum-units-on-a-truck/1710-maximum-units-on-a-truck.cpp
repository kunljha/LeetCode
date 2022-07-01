class Solution {
public:
    static bool myCmp(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), myCmp);
        
        int maxUnits = 0;
        
        for(auto &box : boxTypes) {
            if(box[0] <= truckSize) {
                maxUnits += box[0] * box[1];
                truckSize -= box[0];
            } else {
                maxUnits += truckSize*box[1];
                break;  
            }
        }
        
        return maxUnits;       
    }    
};