class MinStack {
private: 
    stack<int> st;
    stack<int> auxSt;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        
        if(auxSt.empty() || val <= auxSt.top())
            auxSt.push(val);
    }
    
    void pop() {
        int cur = st.top();
        st.pop();
        if(auxSt.top() == cur)
            auxSt.pop();    
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() { 
        return auxSt.top();
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