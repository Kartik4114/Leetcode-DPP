class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        
        int n=startTime.size();

        vector<int> gap;
        gap.push_back(startTime[0]);
        for(int i=1;i<n;i++){
            gap.push_back(startTime[i]-endTime[i-1]);
        }

        gap.push_back(eventTime-endTime[n-1]);

        int g=gap.size();
        vector<int> largestRight(g,0);

        for(int i=g-2;i>=0;i--){
            largestRight[i]=max(largestRight[i+1],gap[i+1]);
        }

        vector<int> largestLeft(g,0);

        for(int i=2;i<g;i++){
            largestLeft[i]=max(largestLeft[i-1],gap[i-2]);
        }

        int maxTime=0;
        for(int i=1;i<g;i++){

            int meetingTime=endTime[i-1]-startTime[i-1];

            if(meetingTime<=max(largestLeft[i],largestRight[i])){
                maxTime=max(maxTime,meetingTime+gap[i-1]+gap[i]);
            }
            maxTime=max(maxTime,gap[i-1]+gap[i]);
        }

        return maxTime;
    }
};