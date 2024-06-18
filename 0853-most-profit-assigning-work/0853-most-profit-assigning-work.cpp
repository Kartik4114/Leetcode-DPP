class Solution {
public:
    int a1(vector<int>& difficulty, vector<int>& profit, vector<int>& worker){
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

    int a2(vector<int>& difficulty, vector<int>& profit, vector<int>& worker){
        int n=difficulty.size();
        int m=worker.size();

        priority_queue<pair<int,int>> pq;

        for(int i=0;i<n;i++){
            pq.push({profit[i],difficulty[i]});
        }

        sort(worker.begin(),worker.end(),greater<int>()); // in descending order

        int i=0;
        int totalProfit=0;

        while(i<m && !pq.empty()){
            if(pq.top().second > worker[i]){
                pq.pop();
            } else {
                totalProfit+=pq.top().first;
                i++;
            }

        }
        
        return totalProfit;

    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        // APPROACH 1:- USING SIMPLE ARRAY FOR STORING ELEMENT
        // return a1(difficulty, profit,worker);

        // APPROACH 2:- USING PRIORITY QUEUE FOR GETTING MAX ELEMENT
        return a2(difficulty, profit,worker);


    }
};