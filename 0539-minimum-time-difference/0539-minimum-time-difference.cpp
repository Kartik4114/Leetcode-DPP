class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        int n=timePoints.size();

        vector<int> minutes(n); // O(n) space

        for(int i=0;i<n;i++){
            string time=timePoints[i];

            string hourSubstr=time.substr(0,2);
            string minSubstr=time.substr(3);

            int hourInt=stoi(hourSubstr);
            int minInt=stoi(minSubstr);

            minutes[i]=hourInt*60+minInt;
        }

        sort(minutes.begin(),minutes.end());

        int result=INT_MAX;
        for(int i=1;i<n;i++){

            int diff=minutes[i]-minutes[i-1];
            result=min(result,diff);
        }

        return min(result,24*60-minutes[n-1]+minutes[0]);
    }
};