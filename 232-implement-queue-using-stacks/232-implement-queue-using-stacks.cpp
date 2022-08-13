class MyQueue {
private: stack<int> input, output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
     int pop() {
        int x = peek();
        output.pop();
        return x;
    }
    
    int peek() {
         if (output.empty()) {
            while (not input.empty()) {
                output.push(input.top());
                input.pop();
            }
         }
         return output.top(); 
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */