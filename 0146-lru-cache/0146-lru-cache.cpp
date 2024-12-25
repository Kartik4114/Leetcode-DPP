class LRUCache {
public:
    // Brute Force Approach :- TLE
    //  Using Vector and then using erase and all funtion for deleting
    // T.C :- O(n^2) , S.C :- O(n)

    // OPTIMISED APPROACH :- USING DOUBLY LINKED LIST
    // T.C :- O(1) , S.C :- O(n)

    list<int> dll;
    map<int,pair<list<int>::iterator,int>> mp;
    int n;
    LRUCache(int capacity) {
        n=capacity;
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
            mp[key]= {dll.begin(),value};
            n--;
        }

        if(n<0){

            int keyToDel=dll.back();
            mp.erase(keyToDel);

            dll.pop_back();
            n++;
        }


    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */