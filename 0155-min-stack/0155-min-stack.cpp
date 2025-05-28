class MinStack {
public:
    stack<long long> st;
    long long minEl=INT_MAX;

    MinStack() {
        
    }
    
    void push(int val) {
        
        if(!st.empty()){

            if(val<minEl){
                long long newVal=2LL*val-minEl;
                st.push(newVal);
                minEl=val;
            } else {
                st.push(val);
            }
        } else {
            st.push(val);
            minEl=val;
        }

    }
    
    void pop() {
        
        long long top=st.top();
        st.pop();

        if(top<minEl){
            minEl=2*minEl-top;
        }
    }
    
    int top() {
        
        if(st.top()<minEl){
            return minEl;
        }
        return st.top();
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