class Solution {
public:
    int memo[101][101];
    
int helper(int i, int j) {
    if (i < 0 || j < 0) return 0;
    if (i == 0 && j == 0) return 1;
    if (memo[i][j] != -1) return memo[i][j];

    int ans = 0;
    ans += helper(i - 1, j);
    ans += helper(i, j - 1);

    return memo[i][j] = ans;
}

    int a3(int m,int n){

        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=1;
                else {
                    int up=0;
                    int left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];

                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        
        // T.C :- FOR RECURSION O(2^(M*N))
        // S.C :- O(STACK SPACE), O(PATH_LENGTH) , O((M-1)*(N-1));

        // T.C :- FOR MEMOIZZATION O(M*N)
        // S.C :- O(STACK SPACE) i.e O((M-1)*(N-1)) + O(M*N);
        // memset(memo,-1,sizeof(memo));
        // return helper(m-1,n-1);

        // approach 3:- using dynamic programming
        // T.C:- O(M*N), S.C :- O(M*N)
        return a3(m,n);


        
        
    }
};