class CustomStack {
public:
    stack<int> st;
    int size;
    CustomStack(int maxSize) {
        size=maxSize;
    }
    
    void push(int x) {
        
        if(st.size()>=size) return;

        st.push(x);
    }
    
    int pop() {
        
        if(st.empty()) return -1;

        int top=st.top();
        st.pop();
        return top;

    }
    
    void increment(int k, int val) {
        
        stack<int> temp;

        
        while(!st.empty()){
            
            if(st.size()>k) temp.push(st.top());
            else temp.push(st.top()+val);
            st.pop();
        }
        cout<<endl;

        while(!temp.empty()){
            cout<<temp.top()<<" ";
            st.push(temp.top());
            temp.pop();
        }
        cout<<endl;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */