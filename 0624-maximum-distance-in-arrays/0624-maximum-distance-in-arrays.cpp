class Solution {
public:
    int a1(vector<vector<int>> &arrays){
        int m=arrays.size();
        vector<int> minDist;
        vector<int> maxDist;

        for(auto &arr:arrays){
            
            int n=arr.size();
            minDist.push_back(arr[0]);
            maxDist.push_back(arr[n-1]);
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

        if(minIndex==maxIndex){

            int diff1=abs(secondMax-firstMin);
            int diff2=abs(secondMin-firstMax);

            return max(diff1,diff2);
        }

        int dist=abs(firstMin-firstMax);
        return dist;
    }

    int a2(vector<vector<int>> &arr){

        int m=arr.size();

        int diff=0;
        int mini=1e5;
        int maxi=-1e5;

        for(auto &a:arr){
            int n=a.size();

            int a0=a[0];
            int aN=a[n-1];

            int minDiff=aN-mini;
            int maxDiff=maxi-a0;
            diff=max({diff,minDiff,maxDiff});
            mini=min(a0,mini);
            maxi=max(aN,maxi);
        }
        return diff;
    }
    int maxDistance(vector<vector<int>>& arrays) {
        
        // APPROACH 1:- MY APPROACH 
        // FINDING FIRST AND SECOND MIN AND MAX
        // T.C :- O(N) , S.C :- O(N)
        // return a1(arrays);

        // APPROACH 2:- SAME APPROACH BUT WAY OF WRITING IS SHORT
        // T.C :- O(N) , S.C :- O(1)
        return a2(arrays);

    }
};