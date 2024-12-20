class MinStack {
public:
    // APPROACH 1:- USING PAIR IN A STACK
    // T.C :- O(N) , S.C :- O(2*N)

    // stack<pair<int,int>> st;
    // MinStack() {
        
    // }
    
    // void push(int val) {
        
    //     if(st.empty()) st.push({val,val});
    //     else {
            
    //         int currMin=st.top().second;
    //         st.push({val,min(val,currMin)});
    //     }
    // }
    
    // void pop() {
        
    //     st.pop();
    // }
    
    // int top() {
        
    //     return st.top().first;
    // }
    
    // int getMin() {
    //     return st.top().second;
    // }

    // APPROACH 2:- WITHOUT USING PAIR IN STACK (OPTIMISED IN SPACE)
    // T.C :- O(N) , S.C :- O(N)

    stack<long long> st;
    long long minEl=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(st.empty()){
            st.push(val);
            minEl=val;
        } else {

            if(val<minEl) {

                long long newVal=2*1LL*val-minEl;
                st.push(newVal);
                minEl=val;
            } else {

                st.push(val);
            }
        }
    }
    
    void pop() {
        
        long long top=st.top();
        st.pop();

        if(top<minEl) {
            minEl=2*minEl - top;
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