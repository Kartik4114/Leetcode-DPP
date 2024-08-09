class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();

        int minRowCnt=0;
        for(int i=0;i<m;i++){

            int k=n-1;
            int j=0;
            while(j<=k){
                if(grid[i][j]!=grid[i][k]) minRowCnt++;
                j++;
                k--;
            }
        }

        int minColCnt=0;
        for(int j=0;j<n;j++){

            int k=m-1;
            int i=0;
            while(i<=k){
                if(grid[i][j]!=grid[k][j]) minColCnt++;
                i++;
                k--;
            }
        }

        int ans=min(minRowCnt,minColCnt);
        return ans;
    }
};