class Solution {
public:
    int memo[201][201];
    int a1(vector<vector<int>>& grid,int i,int j){
        if(i==0 && j==0) return grid[i][j];

        if(i<0 || j<0) return 1e9;

        if(memo[i][j]!=-1) return memo[i][j];

        int up=grid[i][j]+a1(grid,i-1,j);
        int left=grid[i][j]+a1(grid,i,j-1);

        return memo[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
    
    // APPROACH 1:- USING RECURSION +MEMO
        int n=grid.size();
        int m=grid[0].size();

        memset(memo,-1,sizeof(memo));
        return a1(grid,n-1,m-1);
    }
};