class Solution {
public:
    
    bool canAchieve(vector<int> &start,int d,long long midNum){
        
        int n=start.size();
        
        long long numTaken=-1;
        for(int i=0;i<n;i++){
            
            if(i==0){
                numTaken=start[0];
                continue;
            }
            
            long long currNum = max(numTaken + (long long)midNum, (long long)start[i]);
            if (currNum <=(long long)(start[i] + d)) { 
                numTaken = currNum; 
            } else return false;
             
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        
        int n=start.size();
        
        sort(start.begin(),start.end());
        
        long long st=0;
        long long end=start[n-1]-start[0] +d;
        
        int maxScore=0;
        while(st<=end){
            
            long long mid=(st+end)/2;
            if(canAchieve(start,d,mid)){
                maxScore=mid;
                st=mid+1;
            } else end=mid-1;
        }
        
        return maxScore;
    }
};