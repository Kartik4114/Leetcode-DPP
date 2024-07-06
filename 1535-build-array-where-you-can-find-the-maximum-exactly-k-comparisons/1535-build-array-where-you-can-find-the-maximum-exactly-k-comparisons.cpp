class Solution {
public:
    int N,M,K;
    int mod=1e9+7;
    int memo[51][51][101];
    int solve(int idx,int searchCost,int maxSoFar){

        // Base Case
        if(idx>=N){
            if(searchCost==K){
                return 1;
            } 
             return 0;
        }

        if(memo[idx][searchCost][maxSoFar]!=-1) return memo[idx][searchCost][maxSoFar];
        int result=0;
        for(int i=1;i<=M;i++){

            if(i>maxSoFar){
                result=(result+solve(idx+1,searchCost+1,i))%mod;
            } else {
                result=(result+solve(idx+1,searchCost,maxSoFar))%mod;
            }
        }

        return memo[idx][searchCost][maxSoFar]= result;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;

        memset(memo,-1,sizeof(memo));
        return solve(0,0,0);
    }
};