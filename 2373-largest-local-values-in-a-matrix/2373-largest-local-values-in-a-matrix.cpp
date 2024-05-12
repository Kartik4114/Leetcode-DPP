class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
         // T.C :- O(n*n) 
        // Note we can ignore complexity of two inner for loops bec. we are finding 
        // maximim in 3*3 grid which has O(9) complexity so we can ignore that
        
        int n=grid.size();
        vector<vector<int>> maxLocal(n-2,vector<int>(n-2,-1));

        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){

                int temp=0;
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        temp=max(temp,grid[k][l]);
                    }
                }

                maxLocal[i][j]=temp;
            }
        }
        return maxLocal;
    }
};