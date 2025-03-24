class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        int n=meetings.size();

        sort(meetings.begin(),meetings.end());
        long long  freeDays=meetings[0][0]-1;

        int prevBusyDay=meetings[0][1];

        for(int i=1;i<n;i++){

            if(meetings[i][0]-prevBusyDay>0){
                freeDays+=(meetings[i][0]-prevBusyDay-1);
            }

            prevBusyDay=max(prevBusyDay,meetings[i][1]);
        }

        prevBusyDay=max(prevBusyDay,meetings[n-1][1]);
        freeDays+=(days-prevBusyDay);
        return freeDays;
    }
};