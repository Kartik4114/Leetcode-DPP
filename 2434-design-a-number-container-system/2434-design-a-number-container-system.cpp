class NumberContainers {
public:

// APPROACH 1 :- MY APPROACH ALSO 
// USING SETS IN MAP
//  Space Complexity :- O(n)
// Time Complexity :- Find-> O(1) , Change -> O(logn) 

    // unordered_map<int,int> idxToNum;
    // unordered_map<int,set<int>> numToIdx;

    // NumberContainers() {
        
    // }
    // void change(int index, int number) {
        
    //     if(idxToNum.find(index)!=idxToNum.end()){
    //         int prevNum=idxToNum[index];
    //         numToIdx[prevNum].erase(index);

    //         // We are doing this because if we want delete when no element is present in num
    //         // then it will give 0 when we will do *st.begin() but we want 0
            
    //         if(numToIdx[prevNum].size()==0) numToIdx.erase(prevNum);
    //     } 

    //     numToIdx[number].insert(index);
    //     idxToNum[index]=number;
    // } 
    
    // int find(int number) {
        
    //     if(numToIdx.find(number)!=numToIdx.end()){
    //         return *numToIdx[number].begin();
    //     }

    //     return -1;
    // }

    // Using Priority Queue instead of sets
    // Here it is the question of LAZY UPDATE

    unordered_map<int,int> idxToNum;
    unordered_map<int,priority_queue<int,vector<int>,greater<int>>> numToIdx;

    NumberContainers() {
        
    }
    void change(int index, int number) {
        
        idxToNum[index]=number;
        numToIdx[number].push(index);
    } 
    
    int find(int number) {
        
        if(!numToIdx.count(number)){
            return -1;
        }

        auto pq=numToIdx[number];
        while(!pq.empty()){

            int idx=pq.top();

            if(idxToNum[idx]==number){
                return idx;
            }
            pq.pop();
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