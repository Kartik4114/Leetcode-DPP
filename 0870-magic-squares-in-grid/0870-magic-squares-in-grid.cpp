class Solution {
public:
    bool checkSquare(vector<vector<int>>& grid,int i,int j){

        set<int> st;
        
        vector<int> rowSum(3,0);
        vector<int> colSum(3,0);
        vector<int> diagonalSum(2,0);

        for(int row=0;row<3;row++){
            for(int col=0;col<3;col++){
                // cout<<"B"<<endl;
                rowSum[row]+=grid[i+row][j+col];
                colSum[col]+=grid[i+row][j+col];

                if(row==col){
                    // cout<<"C"<<endl;
                    diagonalSum[0]+=grid[i+row][j+col];
                }
                if (row + col == 2) {
                    diagonalSum[1] += grid[i + row][j + col];
                }
                st.insert(grid[i+row][j+col]);
            }
        }
        int checkCnt=0;
        if(rowSum[0]==rowSum[1] && rowSum[1]==rowSum[2]) checkCnt++;
        if(colSum[0]==colSum[1] && colSum[1]==colSum[2]) checkCnt++;
        if(diagonalSum[0]==diagonalSum[1]) checkCnt++;

        return ((checkCnt==3) && (st.size()==9) && (*st.begin()==1 && *st.rbegin()==9));
        
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int SquareCnt=0;
        int m=grid.size();
        int n=grid[0].size();

        int result=0;
        for(int i=0;i<m-2;i++){
            for(int j=0;j<n-2;j++){
                
                cout<<"A"<<endl;
                bool isMagic=checkSquare(grid,i,j);
                if(isMagic){
                    result++;
                }
            }
        }
        return result;
    }
};