class Solution {
public:
    int m,n;
    vector<vector<int>> directions{{-1,0},{0,1},{1,0},{0,-1}};
    int solve(vector<vector<int>>& grid,int i,int j){
        
        if(i<0 || i>=m || j<0 || j>=n){
            return 0;
        }
        if(grid[i][j]==0) return 0;
        
        int originalGoldValue= grid[i][j];
        grid[i][j]=0;

        int maxGold=INT_MIN;

        for(auto &dir: directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];

            maxGold=max(maxGold,solve(grid,new_i,new_j));
        }
        grid[i][j]=originalGoldValue;
        return maxGold+originalGoldValue;

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int result=0;
        m=grid.size();
        n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                
                    result=max(result,solve(grid,i,j));
                }
            }
        }
        return result;
    }
};