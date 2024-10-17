class Solution {
public:

    int maximumSwap(int num) {
        
        string numStr=to_string(num);
        int n=numStr.size();

        priority_queue<pair<char,int>> pq;

        for(int i=0;i<n;i++){
            int ch=numStr[i];
            pq.push({ch,i});
        }

        for(int i=0;i<n;i++){
            
            char ch=pq.top().first;
            int idx=pq.top().second;

            if(numStr[i]!=ch){
                swap(numStr[i],numStr[idx]);
                break;
            } else {

                if(i==idx) {
                    while(!pq.empty() && pq.top().first == numStr[i]) pq.pop();
                }
            }
        }

        int finalNum=stoi(numStr);
        return finalNum;
    }

};