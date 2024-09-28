class MyCalendar {
public:
    unordered_map<int,int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        for(auto &it:mp){
            if(start<it.second && end>it.first) return false;
        }
        // cout<<"M"<<endl;
        mp[start]=end;
        // cout<<mp.size()<<endl;
        return true;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */