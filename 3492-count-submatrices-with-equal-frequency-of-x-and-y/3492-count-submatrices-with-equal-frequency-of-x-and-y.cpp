class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> prefixOfX(m+1,vector<int> (n+1,0));
        vector<vector<int>> prefixOfY(m+1,vector<int> (n+1,0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){

                int toAddForX=0;
                int toAddForY=0;

                if(grid[i-1][j-1]=='X') toAddForX=1;

                if(grid[i-1][j-1]=='Y') toAddForY=1;

                prefixOfX[i][j]=prefixOfX[i-1][j]+prefixOfX[i][j-1]-prefixOfX[i-1][j-1]+toAddForX;
                prefixOfY[i][j]=prefixOfY[i-1][j]+prefixOfY[i][j-1]-prefixOfY[i-1][j-1]+toAddForY;
            }
        }

        int cnt=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(prefixOfX[i][j]==prefixOfY[i][j] && prefixOfX[i][j]>0){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};