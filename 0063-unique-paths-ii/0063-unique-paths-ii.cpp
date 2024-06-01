class Solution {
public:
    int memo[101][101];

    int helper(vector<vector<int>>& obstacleGrid,int m,int n,int i,int j){
        if(i>=m || j>=n || i<0 || j<0 || obstacleGrid[i][j]==1) return 0;

        if(i==m-1 && j==n-1) return 1;

        if(memo[i][j]!=-1) return memo[i][j];

        obstacleGrid[i][j]=1;
        int ans=0;
        ans+=helper(obstacleGrid,m,n,i+1,j);
        ans+=helper(obstacleGrid,m,n,i,j+1);

        obstacleGrid[i][j]=0;

        return memo[i][j]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        memset(memo,-1,sizeof(memo));

        return helper(obstacleGrid,m,n,0,0);
    }
};