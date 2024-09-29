class AllOne {
public:
    unordered_map<string,int> mp;
    AllOne() {
        
    }
    
    void inc(string key) {
        mp[key]++;
    }
    
    void dec(string key) {
        
        mp[key]--;
        if(mp[key]==0) mp.erase(key);
    }
    
    string getMaxKey() {
        
        string maxCntStr;
        int maxi=-1;
        for(auto &it:mp){
            if(it.second>maxi){
                maxCntStr=it.first;
                maxi=max(maxi,it.second);
            }
        }

        return maxCntStr;
    }
    
    string getMinKey() {

        string minCntStr;
        int mini=INT_MAX;
        for(auto &it:mp){
            if(it.second<mini){
                minCntStr=it.first;
                mini=min(mini,it.second);
            }
        }

        return minCntStr;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */