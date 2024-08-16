class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int m=arrays.size();
        vector<int> minDist;
        vector<int> maxDist;

        for(auto &arr:arrays){
            
            int n=arr.size();
            minDist.push_back(arr[0]);
            maxDist.push_back(arr[n-1]);
        }

        
        for(int i=0;i<m;i++){
            cout<<minDist[i]<<" "<<maxDist[i]<<endl;
        }
        
        int firstMin=INT_MAX;
        int secondMin=INT_MAX;
        int minIndex=-1;

        int firstMax=INT_MIN;
        int secondMax=INT_MIN;
        int maxIndex=-1;

        for(int i=0;i<m;i++){

            if(minDist[i]<=firstMin){
                
                secondMin=min(secondMin,firstMin);
                firstMin=min(firstMin,minDist[i]);
                minIndex=i;
            } else if(minDist[i]<=secondMin){
                secondMin=min(secondMin,minDist[i]);
            }
            if(maxDist[i]>=firstMax){
                
                secondMax=max(secondMax,firstMax);
                firstMax=max(firstMax,maxDist[i]);
                maxIndex=i;
            } else if(maxDist[i]>=secondMax){
                secondMax=max(secondMax,maxDist[i]);
            }
        }

        cout<<firstMin<<" "<<secondMin<<endl;
        cout<<firstMax<<" "<<secondMax<<endl;
        if(minIndex==maxIndex){

            int diff1=abs(secondMax-firstMin);
            int diff2=abs(secondMin-firstMax);

            return max(diff1,diff2);
        }

        int dist=abs(firstMin-firstMax);
        return dist;
    }
};