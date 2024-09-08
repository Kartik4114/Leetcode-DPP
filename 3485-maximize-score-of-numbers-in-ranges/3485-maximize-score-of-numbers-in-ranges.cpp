class Solution {
public:
    bool canAchieve(vector<int> start,long long mid,int d){ // here not using &operator in start
        int n=start.size();

        for(int i=1;i<n;i++){

            if(start[i]-start[i-1]>=mid) continue;

            else {
                if(start[i]+d-start[i-1]<mid) return false;
                start[i]=start[i-1]+mid;
            }

        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        
        // 
        int n=start.size();
        sort(start.begin(),start.end());

        long long low=0;
        long long high=start[n-1]+d-start[0];

        long long maxScore=0;
        while(low<=high){
            long long mid=(low+high)/2;

            if(canAchieve(start,mid,d)){
                maxScore=mid;
                low=mid+1;
            } else high=mid-1;
        }

        return maxScore;
    }
};