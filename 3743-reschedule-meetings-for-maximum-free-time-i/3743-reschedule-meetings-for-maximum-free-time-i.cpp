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

        int ans=0;
        int sum=0;

        for(int i=0;i<gap.size() && i<k+1;i++){
            sum+=gap[i];
        }

        ans=sum;
        for(int i=k+1;i<gap.size();i++){
            sum=sum + gap[i]-gap[i-(k+1)];
            ans=max(ans,sum);
        }

        return ans;
    }
};