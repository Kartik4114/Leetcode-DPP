class Solution {
public:
    vector<vector<int>> directions{{0,-1},{0,1},{-1,0},{1,0}}; 
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,bool &isIsland){

        int m=grid1.size();
        int n=grid1[0].size();

        if(i<0 || i>=m || j<0 || j>=n || grid2[i][j]==0) return;

        if(grid1[i][j]==0 && grid2[i][j]==1) isIsland=false;
        
        grid2[i][j]=0;

        for(auto &dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];

            dfs(grid1,grid2,new_i,new_j,isIsland);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int m=grid1.size();
        int n=grid1[0].size();

        int subIslandCnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j] == 1) {
                    bool isSubIsland = true; // Initialize as true
                    dfs(grid1, grid2, i, j, isSubIsland);
                    if(isSubIsland)
                        subIslandCnt++;
                }
            }
        }
        return subIslandCnt;
    }
};