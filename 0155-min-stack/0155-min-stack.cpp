class MinStack {
public:
    // APPROACH 1:- USING PAIR IN A STACK
    // T.C :- O(N) , S.C :- O(2*N)
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(st.empty()) st.push({val,val});
        else {
            
            int currMin=st.top().second;
            st.push({val,min(val,currMin)});
        }
    }
    
    void pop() {
        
        st.pop();
    }
    
    int top() {
        
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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