class MyQueue {
    stack<int> st1, st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st1.empty()){
            int f = st1.top();
            st1.pop();
            st2.push(f);
        }
        st1.push(x);
        while(!st2.empty()){
            int f = st2.top();
            st2.pop();
            st1.push(f);
        }
    }
    
    int pop() {
        int top = st1.top();
        st1.pop();   
        return top;
    }

    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
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