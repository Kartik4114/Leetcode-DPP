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

    int a2(vector<vector<int>> &grid){
        
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];

                else if(i==0){
                    dp[i][j]=grid[i][j]+dp[i][j-1];
                }
                
                else if(j==0) {
                    dp[i][j]=grid[i][j]+dp[i-1][j];
                }

                else {
                    dp[i][j]=grid[i][j] +min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[m-1][n-1];

    }
    int minPathSum(vector<vector<int>>& grid) {
    
    // APPROACH 1:- USING RECURSION +MEMO
        int n=grid.size();
        int m=grid[0].size();

        memset(memo,-1,sizeof(memo));
        // return a1(grid,n-1,m-1);

        // APPROACH 2:- USING DYNAMIC PROGRAMMING
        return a2(grid);
    }
};