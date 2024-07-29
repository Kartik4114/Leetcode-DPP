class Solution {
public: 
    int memoIncr[1001][1001][4];
    int memoDecr[1001][1001][4];
    int solveIncr(vector<int> &rating,int idx,int prev,int cnt){
        int n=rating.size();
        if(cnt==3){
           return 1;
        }

        if(idx>=n) return 0;
        
        if( prev!=-1 && memoIncr[idx][prev][cnt]!=-1) return memoIncr[idx][prev][cnt];

        int result=0;
        if(prev==-1 || rating[prev]<rating[idx]){
            
           result+= solveIncr(rating,idx+1,idx,cnt+1);
        }
        result+=solveIncr(rating ,idx+1,prev,cnt);
       if(prev!=-1) memoIncr[idx][prev][cnt]=result;
       return result;
    }

    int solveDecr(vector<int> &rating,int idx,int prev,int cnt){
        int n=rating.size();
        if(cnt==3){
           return 1;
        }
        
        if(idx>=n) return 0;
        
        if( prev!=-1 && memoDecr[idx][prev][cnt]!=-1) return memoDecr[idx][prev][cnt];

        int result=0;
        if(prev==-1 || rating[prev]>rating[idx]){
            
           result+= solveDecr(rating,idx+1,idx,cnt+1);
        }
        result+=solveDecr(rating ,idx+1,prev,cnt);
         if(prev!=-1 ) memoDecr[idx][prev][cnt]=result;
         return result;
    }

    int numTeams(vector<int>& rating) {
        
        int totalCnt=0;
        memset(memoIncr,-1,sizeof(memoIncr));
        memset(memoDecr,-1,sizeof(memoDecr));
        totalCnt+=solveIncr(rating,0,-1,0);
        totalCnt+=solveDecr(rating,0,-1,0);

        return totalCnt;
    }
};