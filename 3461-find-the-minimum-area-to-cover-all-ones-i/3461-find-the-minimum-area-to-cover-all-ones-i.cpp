class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int m=grid.size();
        
        int n=grid[0].size();
        
        vector<int> row;
        vector<int> col;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        
        int minR=*min_element(row.begin(),row.end());
        int maxR=*max_element(row.begin(),row.end());
        
        int minC=*min_element(col.begin(),col.end());
        int maxC=*max_element(col.begin(),col.end());
        
        int maxArea=(maxR-minR+1) * (maxC-minC+1);
        return maxArea;
        
    }
};