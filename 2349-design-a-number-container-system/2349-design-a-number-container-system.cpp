class NumberContainers {
private :
    map<int, int> container;
    
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        container[index] = number; // key --> index, value --> number
    }
    
    int find(int number) {
        for(auto it : container) {
            if(it.second == number)
                return it.first;
        }
        
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index, number);
 * int param_2 = obj->find(number);
 */