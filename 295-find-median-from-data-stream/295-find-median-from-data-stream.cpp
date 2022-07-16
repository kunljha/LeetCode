class MedianFinder {
private: 
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
    
public:
//     MedianFinder() {
        
//     }
    
    void addNum(int num) {
        if(maxH.empty())
            maxH.push(num);
        else {
            if(maxH.size() > minH.size()) {
                if(num > maxH.top()) {
                    minH.push(num);
                } else {
                    minH.push(maxH.top());
                    maxH.pop();
                    maxH.push(num);
                }
            } else {
                if(num > maxH.top()) {
                    minH.push(num);
                    maxH.push(minH.top());
                    minH.pop();
                } else {
                    maxH.push(num);
                }   
            }
        }   
    }
    
    double findMedian() {
        if(maxH.size() == minH.size()) return maxH.empty() ? 0 : (double)(maxH.top() + minH.top()) / 2;
        else return maxH.size() > minH.size() ? maxH.top() : minH.top(); 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */