class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        
        int n=startTime.size();

        vector<int> gap;
        gap.push_back(startTime[0]);

        for(int i=1;i<n;i++){
            gap.push_back(startTime[i]-endTime[i-1]);
        }

        gap.push_back(eventTime-endTime[n-1]);


        // SLIDING WINDOW
        int currSum=0;
        int maxSum=0;
        for(int i=0;i<gap.size();i++){
            currSum+=gap[i] - ((i>=k+1) ? gap[i-(k+1)] : 0);
            maxSum=max(maxSum,currSum);
        }

        return maxSum;
    }
};