class MyStack {
public:
    // APPROACH 1 (USING TWO QUEUES)
    // T.C :- PUSH = O(n), POP = O(1) , TOP = O(1) , EMPTY = O(1) 

    // queue<int> q1;
    // queue<int> q2;

    // MyStack() {
        
    // }
    
    // void push(int x) {
        
    //     q2.push(x);

    //     while(!q1.empty()){
    //         q2.push(q1.front());
    //         q1.pop();
    //     }
    //     swap(q1,q2);
    // }
    
    // int pop() {
        
    //     int front=q1.front();
    //     q1.pop();
    //     return front;
    // }
    
    // int top() {
    //     return q1.front();
    // }
    
    // bool empty() {
        
    //     if(q1.empty()) return true;
    //     return false;
    // }


    // APPROACH 2 (USING ONE QUEUES)
    // T.C :- PUSH = O(n), POP = O(1) , TOP = O(1) , EMPTY = O(1) 


    queue<int> q1;

    MyStack() {
        
    }
    
    void push(int x) {
        
        q1.push(x);

        int n=q1.size();

        for(int i=0;i<n-1;i++){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        
        int front=q1.front();
        q1.pop();
        return front;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        
        if(q1.empty()) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */