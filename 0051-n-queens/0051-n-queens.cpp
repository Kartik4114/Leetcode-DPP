class Solution {
public:
    vector<vector<string>> result;

    bool isSafe(vector<string> &board,int row,int col){

            // checking row
            int n=board.size();
            for(int i=row-1;i>=0;i--){
                if(board[i][col]=='Q') return false;
            }

            for(int i=row-1,j=col-1;i>=0 && j>=0 ;i--,j--){
                
                if(board[i][j]=='Q') return false;
            }

             for(int i=row-1,j=col+1;i>=0 && j<n ;i--,j++){
                
                if(board[i][j]=='Q') return false;
            }

            return true;

    }
    void a1(vector<string> &board,int row){
        int n=board.size();
        if(row>=n){
            result.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(isSafe(board,row,col)){

            board[row][col]='Q';
            a1(board,row+1);
            board[row][col]='.';

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n,string(n,'.'));
        a1(board,0);

        return result;

    }
};