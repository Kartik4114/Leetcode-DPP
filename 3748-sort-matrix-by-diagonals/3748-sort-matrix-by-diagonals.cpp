class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int d = 0;
        
        while (d < n) {
            vector<int> diagonal;
            
            int i = d;
            int j = 0;
            while (i < n && j < n) {
                
                diagonal.push_back(grid[i][j]);
                i++; j++;
            }
            
            sort(diagonal.rbegin(), diagonal.rend());
            
            i = d;
            j = 0;
            int k = 0;
            
            while (i < n && j < n) {
                grid[i][j] = diagonal[k];
                
                i++;
                j++;
                k++;
            }
            
            d++;
        }
        
        int d1 = 1;
        while (d1 < n) {
            
            vector<int> diagonal;
            
            int i = 0, j = d1;
            
            
            while (i < n && j < n) {
                diagonal.push_back(grid[i][j]);
                i++; j++;
            }
            
            sort(diagonal.begin(), diagonal.end());
            
            i = 0, j = d1;
            int k = 0;
            
            while (i < n && j < n) {
                
                grid[i][j] = diagonal[k];
                
                i++; 
                j++; 
                k++;
            }
            
            d1++;
        }
        
        return grid;
    }
};