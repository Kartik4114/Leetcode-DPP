class Solution {
public:
    vector<vector<string>> result;

    // for approach 2:
    unordered_set<int> cols;
    unordered_set<int> diag;
    unordered_set<int> antiDiag;

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
    void a2(vector<string> &board,int row){
        
        int n=board.size();
        if(row>=n){
            result.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            
            int diagConstant =row+col;
            int antiDiagConstant =row-col;
            if(cols.find(col)!=cols.end() || diag.find(diagConstant)!=diag.end() || 
                antiDiag.find(antiDiagConstant)!=antiDiag.end()){
                continue;
            }
                cols.insert(col);
                diag.insert(diagConstant);
                antiDiag.insert(antiDiagConstant);

                board[row][col]='Q';

                a2(board,row+1);

                cols.erase(col);
                diag.erase(diagConstant);
                antiDiag.erase(antiDiagConstant);
                board[row][col]='.';
            }
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
        
        // APPROACH 1:- using separate code for checking isSafe
        //  T.C :-  Approx.O(N!)
        // S.C :- O(N) system stack

        vector<string> board(n,string(n,'.'));

        // a1(board,0);

        // APPROACH 2:- using unordered_set for checking isSafe
        //  T.C :-  Approx.O(N!)
        // S.C :- O(N) auxillary space

        a2(board,0);
        return result;
    }
};