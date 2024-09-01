class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        int size=original.size();

        if(m*n!=size) return {};
        vector<vector<int>> ans(m,vector<int>(n));

        int row=-1;
        for(int col=0;col<size;col++){

            if(col%n==0){
                row++;
            }
            if(row<m)
            ans[row][col%n]=original[col];
        }

        return ans;
        
    }
};