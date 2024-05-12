class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> arr(n,vector<int>(m,INT_MIN));
        
        arr[n-1][m-1] = grid[n-1][m-1];
        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(i < n-1){
                    arr[i][j] = max(arr[i+1][j], arr[i][j]);
                }
                
                if(j < m-1){
                    arr[i][j] = max(arr[i][j+1], arr[i][j]);
                }
                
                arr[i][j] = max(arr[i][j], grid[i][j]);
            }
        }
        
        int score = INT_MIN;
        
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(i<n-1){
                    score=max(score,(arr[i+1][j]-grid[i][j]));
                }
                if(j<m-1){
                    score=max(score,(arr[i][j+1]-grid[i][j]));
                }
            }
        }
        
        return score;
    }
};
