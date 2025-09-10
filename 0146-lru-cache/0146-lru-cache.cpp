class LRUCache {
public:
    int size;
    list<int> dll;
    unordered_map<int,pair<list<int>::iterator,int>> mp;

    LRUCache(int capacity) {
        size=capacity;
    }
    
    void mostRecentlyUsed(int key){

        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
    }
    int get(int key) {
        
        if(mp.find(key)==mp.end()) return -1;

        mostRecentlyUsed(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){

            mp[key].second=value;
            mostRecentlyUsed(key);
        } else {

            dll.push_front(key);
            mp[key]={dll.begin(),value};
            size--;
        }

        if(size<0){

            int keyToDel=dll.back();
            dll.pop_back();
            mp.erase(keyToDel);
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */