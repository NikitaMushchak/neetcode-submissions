class MinStack {
public:
    MinStack() {
       
    }
    
    void push(int val) {
        
        m_stack.push(val);
        if (m_deque.empty()) {
            m_deque.push_front(val);
        } else if (val <= m_deque.front()) {
            m_deque.push_front(val);
        } else {
            m_deque.push_back(val);
        }
    }
    
    void pop() {
        int firstDeque = m_deque.front();
        int topStack = m_stack.top();
        // cout << "f deque: " << firstDeque << ", top stack: " << topStack << endl;
        if (topStack == firstDeque) {
            // cout << "front\n"; 
            m_deque.pop_front();
        } else {
            // cout << "back\n";
            m_deque.pop_back();
        }
        // cout << "deque: [";
        // for (auto s: m_deque) {
        //     cout << s << ", ";
        // }
        // cout << "]\n";
        m_stack.pop();
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        return m_deque.front();
    }
private:
    deque<int> m_deque;
    stack<int> m_stack;
};
