class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        int n=profit.size();
        int m=worker.size();

        vector<pair<int,int>> store(n);
        for(int i=0;i<n;i++){
            store[i]={difficulty[i],profit[i]};
        }

        sort(store.begin(),store.end());
        sort(worker.begin(),worker.end());

        int j=0;
        int maxProfit=0;
        int bestProfit=0;
        for(int i=0;i<m;i++){
           
           while(j< n && store[j].first<= worker[i]){
                bestProfit=max(bestProfit,store[j].second);
                j++;
           }

           maxProfit+=bestProfit;
        }
        return maxProfit;
        
    }
};