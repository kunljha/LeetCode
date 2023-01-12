class MinStack {
private: 
    stack<long> st;
    long minEl;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            minEl = val;        
        }
        else {
            if(val >= minEl) 
                st.push(val);
            else {
                st.push((long)2*val - minEl);
                minEl = val;
            }
        }
    }
    
    void pop() {
        if(st.top() >= minEl) 
            st.pop();
        else {
            minEl = 2*minEl - st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.top() >= minEl) 
           return st.top();
        else return minEl;
    }
    
    int getMin() { 
        return minEl;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */