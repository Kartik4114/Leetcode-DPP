class NumberContainers {
public:
    unordered_map<int,int> storeIndices;
    unordered_map<int,set<int>> storeNum;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        
        if(storeIndices.find(index)!=storeIndices.end()){
            int num=storeIndices[index];
            storeNum[num].erase(index);

            if(storeNum[num].size()==0) storeNum.erase(num);
        } 

        storeNum[number].insert(index);
        storeIndices[index]=number;
    } 
    
    int find(int number) {
        
        if(storeNum.find(number)!=storeNum.end()){
            return *storeNum[number].begin();
        }

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */