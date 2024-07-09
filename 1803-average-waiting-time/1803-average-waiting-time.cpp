class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        double waitingTime=0;
        double totalTime=customers[0][0];
        int n=customers.size();

        for(int i=0;i<n;i++){
            if(totalTime<customers[i][0]) totalTime=customers[i][0];
            totalTime+=customers[i][1];
            waitingTime+=(totalTime-customers[i][0]);

        }

        double avgWaitingTime=(waitingTime*1.0)/n;
        return avgWaitingTime;

        // TT WT
        // 5 0
        // 7 2
        // 11 8
        // 14 12
        // 
    }
};