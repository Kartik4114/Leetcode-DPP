class Solution {
public:
    vector<vector<int>> directions{{-1,0},{0,1},{1,0},{0,-1}};
    void solve(vector<vector<int>> &matrix,int i,int j){

        int n=matrix.size();
        if(i<0 || j<0 || j>=n || i>=n || matrix[i][j]==1) return;

        matrix[i][j]=1;
        
        for(auto &dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];

            solve(matrix,new_i,new_j);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        
        int n=grid.size();

        vector<vector<int>> matrix(3*n,vector<int>(3*n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]=='/'){
                    matrix[i*3][j*3+2]=1;
                    matrix[i*3+1][j*3+1]=1;
                    matrix[i*3+2][j*3]=1;
                }
                if(grid[i][j]=='\\'){
                    matrix[i*3][j*3]=1;
                    matrix[i*3+1][j*3+1]=1;
                    matrix[i*3+2][j*3+2]=1;
                }
            }
        }

        int region=0;
        for(int i=0;i<3*n;i++){
            for(int j=0;j<3*n;j++){
                if(matrix[i][j]==0){

                    solve(matrix,i,j);
                    region++;
                }
            }
        }

        return region;
    }
};