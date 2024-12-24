class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        // if(st.empty()) return 1;
        // {100,1} {80,1}   {75,4}

        int count=1;
        while(!st.empty() && st.top().first<=price){
            count+=st.top().second;
            st.pop();
        }

        st.push({price,count});
        return count;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */