class Solution {
public:
    int cnt;
    
    int memo[101][101];
    int helper(vector<vector<int>> &board,int m,int n,int i,int j){
        if(i==m-1 && j==n-1) {
            // cnt++;
            return 1;
        }

        if(memo[i][j]!=-1) return memo[i][j];
        if(i>=m || i<0 || j>=n || j<0 || board[i][j]==1) return 0;

        board[i][j]=1;

            int ans=0;
            ans+= helper(board,m,n,i+1,j);
            ans+= helper(board,m,n,i,j+1);
        

        board[i][j]=0;
        return memo[i][j]=ans;
    }
    int uniquePaths(int m, int n) {
        
        
        vector<vector<int>> board(m,vector<int>(n,0));
        memset(memo,-1,sizeof(memo));

        return helper(board,m,n,0,0);
        
    }
};