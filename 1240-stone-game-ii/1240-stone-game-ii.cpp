class Solution {
public:
    int memo[101][2][101];
    int solve(vector<int> &piles,int i,int person,int maxPick){
        int n=piles.size();
        if(i>=n) return 0;

        if(memo[i][person][maxPick]!=-1) return memo[i][person][maxPick];

        int stones=0;
        int result=(person==0) ? -1 : INT_MAX;

        for(int x=1;x<=min(2*maxPick,n-i);x++){
            
            stones+=piles[i+x-1];
            if(person==0){
                result=max(result,stones+solve(piles,x+i,1,max(maxPick,x)));
            } else{
                result=min(result,solve(piles,x+i,0,max(maxPick,x)));
            }
        }
        return memo[i][person][maxPick]=result;
    }
    int stoneGameII(vector<int>& piles) {
        
        memset(memo,-1,sizeof(memo));
        return solve(piles,0,0,1);
    }
};