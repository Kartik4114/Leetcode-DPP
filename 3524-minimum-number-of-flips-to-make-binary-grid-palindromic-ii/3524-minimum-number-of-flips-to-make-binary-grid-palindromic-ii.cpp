class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();

        int minChanges=0;
        for(int i=0;i<m/2;i++){
            for(int j=0;j<n/2;j++){
                
                int x=grid[i][j];
                x+=grid[m-i-1][j];
                x+=grid[i][n-1-j];
                x+=grid[m-i-1][n-j-1];

                minChanges+=min(x,4-x);
            }
        }

        int midOne=0; // when row is odd
        int pairOne=0;
        if(m%2==1){
            for(int j=0;j<n/2;j++){
                if(grid[m/2][j]!=grid[m/2][n-j-1]){
                    minChanges++;
                    midOne++;
                }
                if(grid[m/2][j]==grid[m/2][n-j-1] && grid[m/2][j]==1){
                    pairOne++;
                }
            }
        }

        if(n%2==1){
            for(int j=0;j<m/2;j++){
                if(grid[j][n/2]!=grid[m-j-1][n/2]){
                    minChanges++;
                    midOne++;
                }
                if(grid[j][n/2]==grid[m-j-1][n/2] && grid[j][n/2]==1){
                    pairOne++;
                }
            }
        }

        if(pairOne%2==1 && midOne==0) minChanges+=2;

        if(m%2==1 && n%2==1 && grid[m/2][n/2]==1) minChanges++;
        return minChanges;
    }
};