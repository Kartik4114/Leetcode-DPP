class Solution {
public:
    int memo[301][11];
    int solve(vector<int> &jd,int d,int idx){
        // Base Case
        int n=jd.size();
        if(d==1){
            int maxD=jd[idx];
            for(int i=idx;i<n;i++){
                maxD=max(maxD,jd[i]);
            }
            return maxD;
        }
        
        if(memo[idx][d]!=-1) return memo[idx][d];
        int maxD=jd[idx];
        int finalResult=INT_MAX;
        for(int i=idx;i<=n-d;i++){

            maxD=max(maxD,jd[i]);
            int result=maxD+solve(jd,d-1,i+1);
            finalResult=min(finalResult,result);

        }

        return memo[idx][d]=finalResult;
    }
    int minDifficulty(vector<int>& jd, int d) {
        
        if(jd.size()<d) return -1;
        memset(memo,-1,sizeof(memo));

        return solve(jd,d,0);
    }
};