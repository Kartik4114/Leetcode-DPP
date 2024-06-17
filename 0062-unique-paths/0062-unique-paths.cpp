class Solution {
public:
    int cnt;
    
    int memo[101][101];
    int helper(int m,int n,int i,int j){
        if(i==m-1 && j==n-1) {
            // cnt++;
            return 1;
        }

        if(memo[i][j]!=-1) return memo[i][j];
        if(i>=m || i<0 || j>=n || j<0) return 0;

            int ans=0;
            ans+= helper(m,n,i+1,j);
            ans+= helper(m,n,i,j+1);

        return memo[i][j]=ans;
    }
    int uniquePaths(int m, int n) {
        
        // T.C :- FOR RECURSION O(2^(M*N))
        // S.C :- O(STACK SPACE), O(PATH_LENGTH) , O((M-1)*(N-1));

        // T.C :- FOR MEMOIZZATION O(M*N)
        // S.C :- O(STACK SPACE) i.e O((M-1)*(N-1)) + O(M*N);
        memset(memo,-1,sizeof(memo));

        return helper(m,n,0,0);
        
    }
};