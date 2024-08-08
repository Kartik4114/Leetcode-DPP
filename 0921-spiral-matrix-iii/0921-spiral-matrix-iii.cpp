class Solution {
public:

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        // S.C :- O(1)
        // T.C :- O((max(row,col))^2);
        
        int size=rows*cols;
        vector<vector<int>> directions{{0,1},{1,0},{0,-1},{-1,0}};

        vector<vector<int>> result;
        int steps=0;
        int dir=0;
        result.push_back({rStart,cStart});
        while(result.size()<size){

            if(dir==0 || dir==2) steps++;

            for(int count=0;count<steps;count++){
                rStart+=directions[dir][0];
                cStart+=directions[dir][1];

                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                    result.push_back({rStart,cStart});
                }
            }

            dir=(dir+1)%4;
        }
        return result;

    }
};