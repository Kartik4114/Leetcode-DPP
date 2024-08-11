class Solution {
public:
    int m,n;
    vector<vector<int>> directions{{0,-1},{0,1},{1,0},{-1,0}};
    void dfs(vector<vector<int>> &grid,int i,int j,vector<vector<bool>> &visited){
        if(i>=m || i<0 || j<0 || j>=n || grid[i][j]==0 || visited[i][j]==true){
            return;
        }
        visited[i][j]=true;
        for(auto &dir:directions){

            int new_i=dir[0]+i;
            int new_j=dir[1]+j;

            dfs(grid,new_i,new_j,visited);
        }

    }

    int noOfIslands(vector<vector<int>> &grid){

        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int islands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    dfs(grid,i,j,visited);
                    islands++;
                }
            }
        }
        return islands;
    }
    int minDays(vector<vector<int>>& grid) {
        
        m=grid.size();
        n=grid[0].size();

        int islands=0;
        islands=noOfIslands(grid);

        if(islands==0 || islands>1) return 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==1){
                    grid[i][j]=0;
                    islands=noOfIslands(grid);

                    if(islands>1 || islands==0) return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;

    }
};