class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
        
    }
    
    // bool a1(int start,int end){
    //     for(auto &it:mp){
    //         if(start<it.second && end>it.first) return false;
    //     }
    //     mp[start]=end;
    //     return true;
    // }

    bool a2(int start,int end){

        auto it=st.lower_bound({start,end});

        //Check if the current event overlaps with the next event
        if(it!=st.end() && it->first<end) return false;

        //Check if the current event overlaps with the previous event
        if(it != st.begin()) {
            auto prevIt = prev(it);
            if(start < prevIt->second) {
                return false;
            }
        }

        st.insert({start, end});
        return true;
    }
    bool book(int start, int end) {
        
        // APPROACH 1:- BRUTE FORCE APPROACH
        // T.C :- O(N^2) , S.C :- O(N)
        // return a1(start,end);

        // APPROACH 2:- OPTIMISED APPROACH (USING LOWER BOUND FUNCTION)
        // T.C :- O(NLOGN) , S.C :- O(N)
        return a2(start,end);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */