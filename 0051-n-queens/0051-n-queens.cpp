class Solution {
public:
    vector<vector<string>> result;

    bool isSafe(vector<string> &board,int row,int col){

        // checking row wise
        int n=board.size();
        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q') return false;
        }

        
        // checking left diagonal
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }

        // checking left diagonal
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    void helper(vector<string> &board,int row){
        
        int n=board.size();
        if(row>=n){
            result.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            
            if(isSafe(board,row,col)){
                board[row][col]='Q';

                helper(board,row+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        // APPROACH 1:- 

        vector<string> board(n,string(n,'.'));

        helper(board,0);
        return result;
    }
};